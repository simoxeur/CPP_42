#include "Session.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "bad arguments\nusage: ./replace <file_name> <str_source> <str_to_replace>\n";
        return 1;
    }
    Session replace_sess(av[1], av[2], av[3]);
    return read_replace(replace_sess);
}
