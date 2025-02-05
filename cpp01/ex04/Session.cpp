#include "Session.hpp"

Session::Session(std::string inf, std::string src, std::string new_one)
	: infile(inf)
	, source(src)
	, new_str(new_one) {}

Session::~Session(){}

std::string Session::get_infile(void) const
{
	return infile;
}

std::string Session::get_outfile(void) const
{
    return infile + ".replace";
}

std::string Session::get_str(std::string member) const
{
	if (member == "source")
		return source;
	if (member == "replace_to")
		return new_str;
	return "";
}
