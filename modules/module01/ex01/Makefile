NAME = Zhorde
SRC = $(shell ls *.cpp)
OBJ = $(SRC:.o=.c)
FLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@
$(NAME):$(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all