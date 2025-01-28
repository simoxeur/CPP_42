#include "Phonebook.hpp"

bool name_valid(std::string name)
{
    for (size_t i = 0; i < name.length(); i++)
        if (isalpha(name[i]) == false && name[i] != ' ')
            return false;
    return true;
}

bool number_valid(std::string number)
{
    for (size_t i = 0; i < number.length(); i++)
        if (isdigit(number[i]) == false && number[i] != '+')
            return false;
    return true;
}

bool is_printable(std::string str)
{
        for (size_t i = 0; i < str.length(); i++)
        if (isprint(str[i]) == false)
            return false;
    return true;
}