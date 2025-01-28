#include "replace.hpp"

int read_replace(Session sess)
{
	std::string line, tmp, join;
	std::ifstream inf{sess.get_infile()};
	std::ofstream outf{sess.get_outfile()};

	if (!outf || !inf)
	{
		std::cerr << "error: couldn't open the file\n";
		return 1;
	}
	std::getline(inf, line);
	tmp = line;
	while (std::getline(inf, line))
	{
		join += tmp + "\n";
		tmp = line;
	}
	join += tmp;
	join = replace(sess, join);
	outf <<join;
	return 0;
}

size_t find_str(std::string collect, std::string to_find, size_t start)
{
	size_t pos = 0;
	while ((pos = collect.find_first_of(to_find[0], start)) < collect.length())
	{
		if (collect.substr(pos, to_find.length()) == to_find)
			return pos;
		start = pos + 1;
	}
	return collect.length();
}

std::string replace(Session sess, std::string readed)
{
	size_t i = 0, ii = 0, j = 0, pos = 0;
	std::string replaced{""};

	replaced.resize(readed.length());
	while (ii < readed.length())
	{
		pos = find_str(readed, sess.get_str("source"), ii);
		if (pos != readed.length())
			replaced.resize(replaced.length() + (sess.get_str("replace_to").length() - sess.get_str("source").length()));
		while (ii < pos)
		{
			replaced[i] = readed[ii];
			i++, ii++;
		}
		j = 0;
		while (j < sess.get_str("replace_to").length())
		{
			replaced[i] = sess.get_str("replace_to")[j];
			i++, j++;
		}
		ii = pos + sess.get_str("source").length();
	}
	return replaced;
}
