#pragma once

#include <iostream>
#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		std::string getIdeas() const;
		void setIdeas(const std::string& ) const;
		~Brain();
		Brain& operator=(const Brain& other);
};

