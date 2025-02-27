NAME = AForm
SRC = AForm.cpp Bureaucrat.cpp main.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS =  -Wall -Wextra -Werror #td=c++98
HEADER = $(shell ls *.hpp)

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