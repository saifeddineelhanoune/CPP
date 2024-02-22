#include "PhoneBook.hpp"

int main(void) {
	PhoneBook annuaire;
	bool run;
	std::string command;

	system("clear");
	run = true;
	while (run && std::cin.good()) // std::cin.good() is a way to check if the input is still valid
	{
		annuaire.show_startup();
		std::cout << ">";
		std::getline(std::cin, command);
		if (command == "ADD")
			(annuaire.add_contact(), system("clear"));
		else if (command == "SEARCH")
			annuaire.search_contact();
		else if (command == "EXIT")
		{
			system("clear");
			std::cout << "you've been exited seccessfuly" << std::endl;
			run = false;
		}
	}
	return (0);
}