#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <exception>

class RPN
{
    private:
        std::string input;
        double result;
        std::stack<double> s;

    public:
    // --------------> cnonical form;
        RPN();
        RPN(std::string);
        RPN(const RPN&);
        RPN& operator=(const RPN&);
        ~RPN();

        void calculate_rpn();
        double get_result();

        class InvalidRPN : public std::exception
        {
            public:
                const char* what(void) const throw();
        };
        class DevisionByZero : public std::exception
        {
            public:
                const char* what(void) const throw();
        };

};

#endif