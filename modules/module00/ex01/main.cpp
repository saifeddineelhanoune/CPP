#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phone;
	bool run;
	std::string command;

	system("clear");
	run = true;
	while (run && std::cin.good()) // std::cin.good() is a way to check if the input is still valid
	{
		phone.show_startup();
		std::cout << ">";
		std::getline(std::cin, command);
		if (command == "ADD")
			(phone.add_contact(), std::cin.clear());
		else if (command == "SEARCH")
			phone.search_contact();
		else if (command == "EXIT")
		{
			system("clear");
			std::cout << "you've been exited seccessfuly" << std::endl;
			run = false;
		}
	}
	return (0);
}
