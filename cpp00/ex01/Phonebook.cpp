#include "Phonebook.hpp"

Contact::Contact()
    : id(-1), first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

Contact::Contact(int id, const std::string &first_name, const std::string &last_name,
                 const std::string &nickname, const std::string &phone_number,
                 const std::string &darkest_secret)
    : id(id), first_name(first_name), last_name(last_name), nickname(nickname),
      phone_number(phone_number), darkest_secret(darkest_secret) {}

PhoneBook::PhoneBook() : current_id(0)
{
    for (int i = 0; i < MAX_CONTACTS; i++){
        c[i] = Contact();
    }
}

std::string intput_data(const std::string &to_search) {
    std::string readed;
    while (true) {
        std::cout << to_search << ": ";
        if (!std::getline(std::cin, readed)) {
            std::cout << "Exiting.\n";
            exit(0);
        }
        if (readed.empty()) {
            std::cout << "empty. Please try again.\n";
            continue;
        }
        if ((to_search == "first name" || to_search == "last name") && !name_valid(readed)) {
            std::cout << "No digits. Please try again.\n";
            continue;
        }
        if (to_search == "phone number" && !number_valid(readed)) {
            std::cout << "no characters. Please try again.\n";
            continue;
        }
        if ((to_search == "nickname" || to_search == "darkest secret") && !is_printable(readed)) {
            std::cout << "printable characters. Please try again.\n";
            continue;
        }
        break;
    }
    return readed;
}

std::string align(std::string source)
{
    const size_t width = 10;
    if (source.length() > width)
        return source.substr(0, width - 1) + ".";
    return source;
}

std::string Contact::get_aligned_data(std::string to_search)
{
    if (to_search == "first name")
        return align(first_name);
    if (to_search == "last name")
        return align(last_name);
    if (to_search == "nickname")
        return align(nickname);
    return "";
}

std::string Contact::get_data(std::string to_search)
{
    if (to_search == "first name")
        return first_name;
    if (to_search == "last name")
        return last_name;
    if (to_search == "nickname")
        return nickname;
    if (to_search == "phone number")
        return phone_number;
    if (to_search == "darkest secret")
        return darkest_secret;

    return "";
}

int PhoneBook::add_contact()
{
    int index = current_id % MAX_CONTACTS;

    std::string first_name = intput_data("first name");
    std::string last_name = intput_data("last name");
    std::string nickname = intput_data("nickname");
    std::string phone_number = intput_data("phone number");
    std::string darkest_secret = intput_data("darkest secret");

    c[index] = Contact(current_id, first_name, last_name, nickname, phone_number, darkest_secret);
    current_id++;
    return std::min(current_id, MAX_CONTACTS);
}


void PhoneBook::get_contact(int n)
{
    if (n == 0){
        std::cout << PH_EMPTY << std::endl;
        return ;
    }
    for(int i = 0; i < n && i < MAX_CONTACTS; i++)
    {
        std::cout << "|" << std::setw(10) << i + 1  << "|"
        << std::setw(10) << c[i].get_aligned_data("first name") << "|"
        << std::setw(10) << c[i].get_aligned_data("last name") << "|"
        << std::setw(10) << c[i].get_aligned_data("nickname") << "|"
        << std::endl;
    }

    std::cout << "Enter index to view details: ";

    std::string input;
    std::getline(std::cin, input);

    if (input.length() == 1 && isdigit(input[0]))
    {
        int index = (input[0] - '0') - 1;
        if (index >= 0 && index < n && index < 8)
        {
            std::cout << "First name: " << c[index].get_data("first name") << "\n";
            std::cout << "Last name: " << c[index].get_data("last name") << "\n";
            std::cout << "Nickname: " << c[index].get_data("nickname") << "\n";
            std::cout << "Phone number: " << c[index].get_data("phone number") << "\n";
            std::cout << "Darkest secret: " << c[index].get_data("darkest secret") << "\n";
            return;
        }
    }

    std::cout << "Invalid index. Returning to main menu.\n";
}