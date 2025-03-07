#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <stdexcept>
#include <cmath>

#include <float.h>
#include <stdlib.h>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        static void convert(std::string);
};

#endif