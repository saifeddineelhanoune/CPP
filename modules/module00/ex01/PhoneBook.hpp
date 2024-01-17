#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
    public:
       PhoneBook();
       ~PhoneBook();
       int add_contact(Contact contact);
       void print_contact(int index) const;
};

#endif