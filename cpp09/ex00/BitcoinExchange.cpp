#include "BitcoinExchange.hpp"

Ressources::Ressources(char* file)
{
    input_file.open(file);
    if(!input_file)
        throw FailOpen();
    db_file.open("data.csv");
    if(!db_file)
        throw FailOpen();

    std::string str;
    std::getline(db_file, str);
    while(std::getline(db_file, str)){
        db_date.push_back(str.substr(0, 10));
        db_rate.push_back(str.substr(str.find(',') + 1));
    }
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

void Ressources::check_date(std::string& date, std::string& err_msg)
{
    std::string year = date.substr(0, 4);
    std::string month = date.substr(date.find('-') + 1, 2);
    std::string day = date.substr(date.find_last_of('-') + 1, 2);
    if(year.length() != 4 || !is_number(year) || month.length() != 2 || !is_number(month) || day.length() != 2 || !is_number(day)){
        date = "";
        err_msg = "Error: date format not valid.";
        return ;
    }
    int y = std::atoi(year.c_str()), m = std::atoi(month.c_str()), d = std::atoi(day.c_str());
    if(!calendrier_valid(y, m, d)){
        date = "";
        err_msg = "Error: date format not valid.";
        return ;
    }
}

void Ressources::check_value(std::string& value, std::string& err_msg)
{
    float v;
    if(!is_number(value) && !is_float(value)){
        value = "";
        if(err_msg.empty())
            err_msg = "Error: value is not valid.";
        return;
    }
    if(is_float(value))
        v = static_cast<float>(std::atof(value.c_str()));
    else
        v = static_cast<float>(std::atoi(value.c_str()));
    if(v > 1000){
        value = "";
        if(err_msg.empty())
            err_msg = "Error: too large a number.";
    }
    if(v < 0){
        value = "";
        if(err_msg.empty())
            err_msg = "Error: not a positive number.";
    }
    return;

}

void Ressources::get_data(std::string format, int id)
{
    std::string date = format.substr(0, format.find('|'));
    std::string value = format.substr(format.find('|') + 1);
    std::size_t del = format.find('|');
    _err_msg.push_back("");
    _rate_exchange.push_back(0);
    if(del == std::string::npos){
        _err_msg[id] = "Error: bad input => " + format;
        _date.push_back("");
        _value.push_back("");
        return;
    }
    erase_sp(date);
    erase_sp(value);
    check_date(date, _err_msg[id]);
    check_value(value, _err_msg[id]);
    _date.push_back(date);
    _value.push_back(value);
}

void Ressources::append_rate(int index)  // index for the date we have in infile inside the vector _date
{
    if(_date[index].empty() || _value[index].empty())
        return;

    int rate_id = 0;  // i will use it to get the closest and less date possible for the date we have
    for(std::size_t db_id = 0; db_id < db_date.size(); db_id++){  // loop for the db content inside a vecotr db_date
        if(db_date[db_id] <= _date[index])
            rate_id = db_id;
        else
            break;
    }
    _rate_exchange[index] = rate_id;
}

void Ressources::validate_infile()
{
    std::string format;
    std::getline(input_file, format);
    if(bad_format(format))
        throw BadFormat();
    int i = 0;
    while(std::getline(input_file, format))
    {
        get_data(format, i);
        append_rate(i);
        i++;
    }
}

void Ressources::display(void)
{
    float value = 0, rate = 0, prod = 0;
    for(std::size_t i = 0; i < _date.size(); i++){
        if(!_date[i].empty() && !_value[i].empty()){
            value = std::atof(_value[i].c_str());
            rate = std::atof(db_rate[_rate_exchange[i]].c_str());
            prod = value * rate;
            std::cout << _date[i] << " => " << value << " = " << prod << '\n';
        }
        else
            std::cout << _err_msg[i] << '\n';
    }
    // std::cout << "\n-----------------\n" << static_cast<float>(2.27) << '\n';
}

const char* Ressources::FailOpen::what() const throw()
{
    return "Error: could not open file.";
}

const char* Ressources::BadFormat::what() const throw()
{
    return "Error: Bad format used on file.";
}