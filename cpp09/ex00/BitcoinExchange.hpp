#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <iomanip>

class Ressources
{
    private:
        std::ifstream input_file;
        std::ifstream db_file;
        std::vector<std::string> _date;
        std::vector<std::string> _value;
        std::vector<int> _rate_exchange;
        std::vector<std::string> _err_msg;
        // std::vector<std::string> output;
        std::vector<std::string> db_date;
        std::vector<std::string> db_rate;

    public:
        Ressources(char *);
        // Ressources(std::ifstream*, std::ifstream*);
        // Ressources(const Ressources&);
        // Ressources& operator=(const Ressources&);
        // ~Ressources();
        void validate_infile();
        void get_data(std::string, int);
        void check_date(std::string&, std::string&);
        void check_value(std::string&, std::string&);
        void append_rate(int);
        void display(void);

        class FailOpen : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class BadFormat : public std::exception
        {
            public:
                const char* what() const throw();
        };


};

#endif