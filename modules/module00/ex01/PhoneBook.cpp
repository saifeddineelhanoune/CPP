#include "PhoneBook.hpp"

#define MAX 3

PhoneBook::PhoneBook() : amount(0), iter(0) {

}

PhoneBook::~PhoneBook() {

}

void PhoneBook::show_startup(void) {
	std::cout << "# PHONEBOOK" << std::endl;
	std::cout << "# Enter your command [ADD, SEARCH, EXIT]:" << std::endl;

}

void PhoneBook::add_contact(void) {
	if (this->amount == MAX)
	{
		std::cout << "# The table contacts is full !" << std::endl;
	}
	if (this->contacts[iter].set_informations(iter))
	{
		this->amount = this->amount >= MAX ? MAX : this->amount + 1;
		iter = (iter + 1) % MAX;
	}
	else
		std::cout << "# Contact not added !" << std::endl;
}

void PhoneBook::show_searched_header(void) {
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->amount; i++)
		this->contacts[i].display_header();
	std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::search_contact(void) {
	int	index;

	if (this->amount == 0)
		std::cout << "# No contact found!, please add one before searching!" << std::endl;
	else {
		this->show_searched_header();
		std::cout << "# Enter Index to display Informations or 0 to Exit\n~";
		while (!(std::cin >> index) || index < 0 || index > this->amount) {
			if (!std::cin.good())
				exit(EXIT_FAILURE);
			std::cout << "# Invalid Index" << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index > 0)
			this->contacts[index - 1].display();
	}
}