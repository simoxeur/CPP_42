#include "BitcoinExchange.hpp"

Ressources::Ressources(){}

Ressources::Ressources(char* file)
{
    infile_path = static_cast<std::string>(file);
    input_file.open(file);
    if(input_file.fail())
        throw FailOpen();
    db_file.open("data.csv");
    if(db_file.fail())
        throw FailOpen();

    std::string str;
    std::getline(db_file, str);
    while(std::getline(db_file, str)){
        _rates[str.substr(0, 10)] = str.substr(str.find(',') + 1);
    }
    db_file.close();
}

Ressources::Ressources(const Ressources& other)
    : infile_path(other.infile_path)
    , _rates(other._rates)
{
    input_file.close();
    input_file.open(infile_path.c_str());
    if(input_file.fail())
        throw FailOpen();
}

Ressources& Ressources::operator=(const Ressources& other)
{
    if(this != &other)
    {
        infile_path = other.infile_path;
        _rates = other._rates;
        input_file.close();
        input_file.open(infile_path.c_str());
        if(input_file.fail())
            throw FailOpen();
    }
    return *this;
}

Ressources::~Ressources()
{
    input_file.close();
}

static void erase_sp(std::string& str)
{
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}

static int bad_format(std::string format)
{
    std::size_t del = format.find('|');
    if(del == std::string::npos)
        return 1;
    std::string date = format.substr(0, format.find('|'));
    std::string value = format.substr(format.find('|') + 1);
    erase_sp(date);
    erase_sp(value);
    if(date.empty() || value.empty())
        return 1;
    if(date != "date" || value != "value")
        return 1;
    return 0;
}

bool calendrier_valid(int y, int m, int d)
{
    if (d <= 0 || d > 31 || m <= 0 || m > 12)
        return false;

    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2)
    {
        bool is_leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (is_leap)
            days_in_month[1] = 29;
    }
    return d <= days_in_month[m - 1];
}

bool is_number(std::string str)
{
    std::size_t i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    for(; i < str.length(); i++){
        if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool is_float(std::string& str)
{
    int fcount = 0, pcount = 0;
    if(str.find('f') != str.length() - 1 || str.find('.') == str.length() || str.find('.') == 0)
        return false;
    for(std::size_t i = 0; i < str.length(); i++){
        if(str[i] == 'f')
            fcount++;
        if(str[i] == '.')
            pcount++;
        if((!std::isdigit(str[i]) && str[i] != 'f' && str[i] != '.') || fcount > 1 || pcount > 1)
            return false;
    }
    if(fcount)
        str.erase(str.find('f'));
    bool ret = (str.find('.') == str.find_last_of('.'));
    return ret;
}

int Ressources::check_date(std::string& date)
{
    std::string year = date.substr(0, 4);
    std::string month = date.substr(date.find('-') + 1, 2);
    std::string day = date.substr(date.find_last_of('-') + 1, 2);
    if(year.length() != 4 || !is_number(year) || month.length() != 2 || !is_number(month) || day.length() != 2 || !is_number(day))
        return 1;
    int y = std::atoi(year.c_str()), m = std::atoi(month.c_str()), d = std::atoi(day.c_str());
    if(!calendrier_valid(y, m, d))
        return 1;
    return 0;
}

int Ressources::check_value(std::string& value)
{
    float v;
    if(!is_number(value) && !is_float(value))
        return 2;
    // if(is_float(value))
        v = static_cast<float>(std::atof(value.c_str()));
    // else
    //     v = static_cast<float>(std::atoi(value.c_str()));
    if(v > 1000)
        return 3;
    if(v < 0)
        return 4;
    return 0;

}

void Ressources::empty_insert(void)  // in case of an error in a line i push an empty string in all the conatiners to just keep the container _lst_err and check after that there is an error
{
    _dates.push_back("");
    _values.push_back("");
    _rate_exchange.push_back("");
}

Ressources::it Ressources::get_data(std::string& format, Ressources::it cur)
{
    int r = 0;

    std::string date = format.substr(0, format.find('|'));
    std::string value = format.substr(format.find('|') + 1);
    std::size_t del = format.find('|');
    if(del == std::string::npos){
        empty_insert();
        _lst_err.push_back("Error: bad input => " + format);
        return ++cur;
    }
    
    erase_sp(date);
    erase_sp(value);
    if((r = check_date(date)) == 1){
        empty_insert();
        _lst_err.push_back("Error: date format not valid.");
        return ++cur;
    }
    std::string err[3] = {"Error: value is not valid.", "Error: too large number.", "Error: not a positive number."};
    if((r = check_value(value)) > 1){
        empty_insert();
        _lst_err.push_back(err[r - 2]);
        return ++cur;
    }
    _dates.push_back(date);
    _values.push_back(value);
    return ++cur;
}

void Ressources::append_rate(it dates_it)  // index for the date we have in infile inside the vector _date
{
    if((*dates_it).empty())
        return;
    m_it rates_it = _rates.begin();
    m_it exchange_it = rates_it;

    for(; rates_it != _rates.end(); rates_it++){  // loop for the db content inside a map _rates
        if((*rates_it).first <= *dates_it)
                exchange_it = rates_it;
        else
            break;
    }
    _rate_exchange.push_back((*exchange_it).second);
}

void Ressources::validate_infile()
{
    it dates_it = _dates.begin();

    std::string format;
    std::getline(input_file, format);
    if(bad_format(format))
        throw BadFormat();
    int i = 0;
    while(std::getline(input_file, format))
    {
        dates_it = get_data(format, dates_it);
        append_rate(dates_it);
        i++;
    }
}

void Ressources::display(void)
{
    it dates_it = _dates.begin();
    it values_it = _values.begin();
    it exchange_rates_it = _rate_exchange.begin();
    it err_it = _lst_err.begin();
    for(; values_it != _values.end(), dates_it != _dates.end(), exchange_rates_it != _rate_exchange.end() ; dates_it++, values_it++, exchange_rates_it++){
        if(!(*dates_it).empty() && !(*values_it).empty() && !(*exchange_rates_it).empty())
            std::cout << *dates_it << " => " << *values_it << " = " << std::atof((*values_it).c_str()) * std::atof((*exchange_rates_it).c_str()) << '\n';
        else{
            std::cout << *err_it << '\n';
            ++err_it;
        }
    }
}

const char* Ressources::FailOpen::what() const throw()
{
    return "Error: could not open file.";
}

const char* Ressources::BadFormat::what() const throw()
{
    return "Error: Bad format used on file.";
}