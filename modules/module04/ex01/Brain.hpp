#pragma once

#include <iostream>
#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		void getIdeas() const;
		void setIdeas(const std::string& idea, int index);
		~Brain();
		Brain& operator=(const Brain& other);
};

