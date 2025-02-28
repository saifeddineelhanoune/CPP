NAME = Form
SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
HEADER = Bureaucrat.hpp Form.hpp

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