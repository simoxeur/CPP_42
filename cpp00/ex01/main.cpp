#include "Phonebook.hpp"

int main()
{
    PhoneBook   my_phonebook;
    std::string cmd;
    int n = 0;

    std::cout << "possible command: ADD, SEARCH, EXIT" << std::endl;
    while (true)
    {
        std::cout << "$ ";
        if (!std::getline(std::cin, cmd)){
            std::cout << "\nExiting.\n";
            return 0;
        }
        if (cmd == "ADD"){
            n = my_phonebook.add_contact();
        }
        else if (cmd == "SEARCH"){
            my_phonebook.get_contact(n);
        }
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "possible command: ADD, SEARCH, EXIT" << std::endl;
    }
    return 0;
}