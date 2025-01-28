#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class Session
{
    private:
        std::string infile;
        std::string outfile;
        std::string source;
        std::string new_str;

    public:
        Session(std::string inf, std::string src, std::string new_one);
        ~Session();
		std::string get_outfile();
        std::string get_infile();
        std::string get_str(std::string member);
};

int			read_replace(Session sess);
std::string	replace(Session sess, std::string line);
size_t		find_str(std::string collect, std::string to_find, size_t start);

#endif