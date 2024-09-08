#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat& other);  // Copy constructor
		~Cat();
		Cat& operator=(const Cat& other);  // Assignment operator
		void makeSound() const;
		void getIdeas() const;
		void setIdeas(const std::string& idea, int index);

};

