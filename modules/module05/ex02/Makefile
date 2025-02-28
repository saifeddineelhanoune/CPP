NAME = AForm
SRC = AForm.cpp Bureaucrat.cpp main.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS =  -Wall -Wextra -Werror -std=c++98 -fsanitize=address
HEADER = AForm.hpp Bureaucrat.hpp \
		PresidentialPardonForm.hpp \
		RobotomyRequestForm.hpp \
		ShrubberyCreationForm.hpp

all: $(NAME)

%.o: %.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@
$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all