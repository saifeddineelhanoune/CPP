#pragma once

#include <iostream>
#include <string>



class Animal {
	protected:
		std::string type;
	public:
		Animal(const std::string& type);
		Animal();
		Animal(const Animal& other);
		Animal &operator=(const Animal& other);
		virtual void makeSound() const;
		std::string getType() const;
		void setType(const std::string& type); 
		virtual ~Animal();
};
