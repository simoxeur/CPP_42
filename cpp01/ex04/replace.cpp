#include "Session.hpp"

int read_replace(const Session& sess)
{
	std::string line, tmp, join;
	std::ifstream inf(sess.get_infile());
	if (!inf.is_open()){
		std::cerr << "error: couldn't open the infile\n";
		return 1;
	}
	std::ofstream outf(sess.get_outfile());
	if (!outf.is_open()){
		std::cerr << "error: couldn't open the outfile\n";
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
	outf << join;
	inf.close();
	outf.close();
	return 0;
}

std::string replace(const Session& sess, std::string readed)
{
    std::string replaced;
    size_t pos = 0, prev = 0;
    const std::string& source = sess.get_str("source");
    const std::string& new_str = sess.get_str("replace_to");
	if (source.empty())
		return readed;

    while ((pos = readed.find(source, prev)) != std::string::npos) {
        replaced.append(readed, prev, pos - prev);  // Append part before match
        replaced.append(new_str);                  // Append replacement
        prev = pos + source.length();              // Move past the match
    }
    replaced.append(readed, prev);                 // Append the rest of the string
    return replaced;
}
