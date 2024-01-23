#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
    public:
       PhoneBook();
       ~PhoneBook();
       int AddContact(Contact contact);
       void Print_contact(int index) const;
       int  GetIndex() const;
       int  ContactNumber() const;
    private:
        int Index;
        int ContactsNumber;
        Contact contact[8];
};

#endif