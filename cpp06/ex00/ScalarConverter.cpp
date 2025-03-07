#include "ScalarConverter.hpp"

bool isChar(std::string s)
{
    return(s.length() == 1 && isprint(s[0]) && !isdigit(s[0]));
}

bool isInt(std::string s, bool int_part)
{
    std::size_t r = 0;
    if(s[0] == '-')
        r++;
    for(std::size_t i = r; i < s.length(); i++){
        if(!isdigit(s[i]) || (r != 0 && int_part))
            return false;
    }
    return true;
}

bool isFloat(std::string s)
{
    if(s == "nanf")
        return true;
    if(!s.find('.') || s.find('.') >= s.length() - 2 || s.find('f') != s.length() - 1)
        return false;
    if(!isInt(s.substr(0, s.find('.')), 0) || !isInt(s.substr(s.find('.') + 1, s.find('f') - s.find('.') - 1), 1))
        return false;
    return true;
}

bool isDouble(std::string s)
{
    if(s == "nan")
        return true;
    if(!s.find('.') || s.find('.') >= s.length() - 1)
        return false;
    if(!isInt(s.substr(0, s.find('.')), 0) || !isInt(s.substr(s.find('.') + 1, s.length() - s.find('.') - 1), 1))
        return false;
    return true;
}

int find_type(std::string s)
{
    int id = (isChar(s)) * 1 + (isInt(s, 0)) * 2 + (isFloat(s)) * 3 + (isDouble(s)) * 4 - 1;
    return id;
}

void printChar(std::string s, std::string type)
{
    if(s == "nan" || s == "nanf"){
        std::cout << "char: impossible" << '\n';
        return ;
    }
    char res = static_cast<char>(type == "int" ? atoi(s.c_str()) : ((type == "float" || type == "double") ? atof(s.c_str()) : s[0]));
    if(!isprint(res) || atof(s.c_str()) > 127 || atof(s.c_str()) < 127){
        std::cout << "char: Non displayable\n";
        return ;
    }
    std::cout << "char: " << res << '\n';
}

void printInt(std::string s, std::string type)
{
    if(s == "nan" || s == "nanf"){
        std::cout << "int: impossible" << '\n';
        return ;
    }
    int res = static_cast<int>(type == "char" ? s[0] : ((type == "float" || type == "double") ? atof(s.c_str()) : atoi(s.c_str())));
    if(std::atof(s.c_str()) > INT_MAX || std::atof(s.c_str()) < INT_MIN){
        std::cout << "int: " << "impossible" << '\n';
        return ;
    }
    std::cout << "int: " << res << '\n';
}

void printFloat(std::string s, std::string type)
{
    if(s == "nan" || s == "nanf"){
        std::cout << "float: nanf" << '\n';
        return ;
    }
    float res = static_cast<float>(type == "char" ? s[0] : (type == "int" ? atoi(s.c_str()) : atof(s.c_str())));
    if(type == "int" && (std::atof(s.c_str()) > INT_MAX || std::atof(s.c_str()) < INT_MIN)){
        std::cout << "float: " << "impossible" << '\n';
        return ;
    }
    std::cout << "float: " << res << (roundf(res) == res ? ".0" : "") << "f\n";
}

void printDouble(std::string s, std::string type)
{
    (void)type;
    if(s == "nan" || s == "nanf"){
        std::cout << "double: " << "nan" << '\n';
        return ;
    }
    double res = static_cast<double>(type == "char" ? s[0] : (type == "int" ? atoi(s.c_str()) : atof(s.c_str())));
    if(type == "int" && (std::atof(s.c_str()) > INT_MAX || std::atof(s.c_str()) < INT_MIN)){
        std::cout << "double: " << "impossible" << '\n';
        return ;
    }
    std::cout << "double: " << res << (roundf(res) == res ? ".0" : "") << "\n";

}

void ScalarConverter::convert(std::string s)
{
    std::string types[4] = {"char", "int", "float", "double"};
    int id = find_type(s);
    if(id == -1 || s.empty()){
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return ;
    }
    printChar(s, types[id]);
    printInt(s, types[id]);
    printFloat(s, types[id]);
    printDouble(s, types[id]);

    // check is the type is right finded
    // std::cout << "the type is " << types[id] << '\n';
}