#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal(const std::string& type);
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal &operator=(const WrongAnimal& other);
		void makeSound() const;
		std::string getType() const;
		void setType(const std::string& type); 
		~WrongAnimal();
};
