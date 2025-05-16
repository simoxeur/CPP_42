#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>
#include <map>
#include <list>
#include <iomanip>

#define DATA_PATH "data.csv"

class Ressources
{
    private:
        std::string infile_path;
        std::ifstream input_file;
        std::ifstream db_file;
        std::list<std::string> _dates;
        std::list<std::string> _values;
        std::list<std::string> _rate_exchange;
        std::list<std::string> _lst_err;
        std::map<std::string, std::string> _rates;

    public:
        Ressources();
        Ressources(char *);
        Ressources(const Ressources&);
        Ressources& operator=(const Ressources&);
        ~Ressources();


        typedef std::list<std::string>::iterator it;
        typedef std::map<std::string, std::string>::iterator m_it;

        void validate_infile();
        it get_data(std::string&, it cur);
        int check_date(std::string&);
        int check_value(std::string&);
        void append_rate(it dates_it);
        void empty_insert(void);
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