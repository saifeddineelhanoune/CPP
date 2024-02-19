#include "PhoneBook.hpp"

int main(void) {
	PhoneBook annuaire;
	bool run;
	std::string command;

	annuaire.show_startup();
	run = true;
	while (run)
	{
		std::cout << ">";
		std::getline(std::cin, command);
		if (command == "ADD")
			annuaire.add_contact();
		else if (command == "SEARCH")
			annuaire.search_contact();
		else if (command == "EXIT")
		{
			std::cout << "you've been exited seccessfuly" << std::endl;
			run = false;
		}
	}
	return (0);
}