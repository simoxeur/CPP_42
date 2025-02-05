#ifndef SESSION_HPP
#define SESSION_HPP

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
		std::string get_outfile() const;
        std::string get_infile() const;
        std::string get_str(std::string member) const;
};

int			read_replace(const Session& sess);
std::string	replace(const Session& sess, std::string line);

#endif