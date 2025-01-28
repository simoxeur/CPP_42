#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

#define MAX_CONTACTS 8
#define PH_EMPTY "the phonebook is empty"

class Contact
{
    private:
        int			id;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact();
        Contact(int id, const std::string &first_name, const std::string &last_name,
                 const std::string &nickname, const std::string &phone_number,
                 const std::string &darkest_secret);
        std::string get_aligned_data(std::string to_search);
        std::string get_data(std::string to_search);

};

class PhoneBook
{
    private:
        Contact c[MAX_CONTACTS];
        int current_id;

    public:
        PhoneBook();
        int     add_contact(void);
        void    get_contact(int n);
};

// #define MSG "possible command: ADD, SEARCH, EXIT"


bool name_valid(std::string name);
bool number_valid(std::string number);
bool is_printable(std::string str);

#endif