class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname, 
            const std::string& phoneNumber, const std::string& darkestSecret);
    // getters and setters for each property
};


class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;

public:
    PhoneBook();
    void add(const Contact& contact);
    void search(int index);
    void exit();
};
#include "Contact.hpp"
#include <iostream>

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname, 
                 const std::string& phoneNumber, const std::string& darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

// Add getter and setter methods here



#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook() : currentIndex(0) {}

void PhoneBook::add(const Contact& contact) {
    contacts[currentIndex] = contact;
    currentIndex++;
    if (currentIndex >= 8) {
        currentIndex = 0;
    }
}

void PhoneBook::search(int index) {
    if (index < 0 || index >= currentIndex) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    // Print contact information
    std::cout << contacts[index].getFirstName() << std::endl;
    std::cout << contacts[index].getLastName() << std::endl;
    std::cout << contacts[index].getNickname() << std::endl;
    std::cout << contacts[index].getPhoneNumber() << std::endl;
}

void PhoneBook::exit() {
    // Exit the program
}


#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string command;
    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            // Repeat for other fields
            Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.add(contact);
        } else if (command == "SEARCH") {
            int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            phoneBook.search(index);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}
