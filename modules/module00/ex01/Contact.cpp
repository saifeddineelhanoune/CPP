#include "Contact.hpp"

Contact::Contact() {
	for (int i = FirstName; i <= Secret; i++)
		this->informations[i] = std::string();
}

Contact::~Contact() {

}

std::string Contact::fields_name[5] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Phone",
	"Darkest Secret"
};

bool Contact::set_informations(int index) {
	this->index = index + 1;
	for (int i = FirstName; i <= Secret; i++) {
		std::cout << "# " << Contact::fields_name[i] << ":\n+";
		std::getline(std::cin, this->informations[i]);
		if (i == Phone) {
			for (size_t j = 0; j < this->informations[i].length(); j++) {
				if (!::isdigit(this->informations[i].at(j))) {
					std::cout << "# Invalid phone number! " << this->informations[i] << std::endl;
					return (false);
				}
			}
		}
	}
	bool is_empty = false;
	for (int i = FirstName; i <= Secret; i++) {
		if (this->informations[i].empty()) {
			is_empty = true;
			break;
		}
	}
	if (is_empty) {
		std::cout << "# Empty contact!" << std::endl;
		return (false);
	}
	std::cout << "# Contact added !" << std::endl;
	return (true);
}

void Contact::display_header() {
	std::cout << "|" << std::setw(10) << this->index;
	for (int i = FirstName; i < Phone; i++) {
		std::cout << "|";
		if (this->informations[i].length() > 10)
			std::cout << this->informations[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->informations[i];
	}
	std::cout << "|" << std::endl;
}

void Contact::display(void) {
	std::cout << "# Contact [" << this->index << "]" << std::endl;
	for (int i = FirstName; i <= Secret; i++) {
		std::cout << Contact::fields_name[i] << ": ";
		std::cout << this->informations[i] << std::endl;
	}
}