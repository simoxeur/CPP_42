#include "replace.hpp"

Session::Session(std::string inf, std::string src, std::string new_one)
	: infile{inf}
	, source{src}
	, new_str{new_one} {}

Session::~Session(){}

std::string Session::get_infile(void)
{
	return infile;
}

std::string Session::get_outfile(void)
{
    return infile + ".replace";
}

std::string Session::get_str(std::string member)
{
	if (member == "source")
		return source;
	if (member == "replace_to")
		return new_str;
	return "";
}
