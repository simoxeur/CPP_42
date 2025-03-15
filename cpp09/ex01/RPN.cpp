#include "RPN.hpp"

RPN::RPN(std::string s) : input(s) {}

// ----------> canonical form

static std::string get_token(std::string str, std::size_t start)
{
    std::string tok = str.substr(start);
    std::size_t del = tok.find(' ');
    if(del == std::string::npos)
        return tok;
    tok = tok.substr(0, del);
    return tok;
}

static void erase_sp(std::string& str)
{
    std::size_t start = 0;
    std::size_t end = str.length() - 1;
    while(str[start] == ' ') start++;
    while(str[end] == ' ') end--;
    str.erase(0, start);
    str.erase(end + 1);
}

void RPN::calculate_rpn()
{
    double a = 0, b = 0;
    std::string token;
    erase_sp(input);
    for(std::size_t i = 0; i < input.length(); i++){
        while(input[i] == ' ') i++;
        token = get_token(input, i);
        if((token.length() >= 2) && token[0] != '-')
            throw InvalidRPN();
        if(std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1])))
            s.push(std::atof(token.c_str()));
        else{
            if(s.size() < 2)
                throw InvalidRPN();
            if(token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/')
                throw InvalidRPN();
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            if(token[0] == '-')
                s.push(b - a);
            else if(token[0] == '+')
                s.push(b + a);
            else if(token[0] == '*')
                s.push(b * a);
            else if(token[0] == '/'){
                if(a == 0)
                    throw DevisionByZero();
                s.push(b / a);
            }

        }
    }
    result = s.top();
}

double RPN::get_result()
{
    return result;
}

const char* RPN::InvalidRPN::what(void) const throw()
{
    return "Error";
}

const char* RPN::DevisionByZero::what(void) const throw()
{
    return "error: devision by 0";
}

