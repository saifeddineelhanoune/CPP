NAME = UnnecessaryViolence
SRC = $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

%.o: %.cpp
	g++ $(FLAGS) -c $< -o $@
$(NAME): $(OBJ)
	g++ $(FLAGS) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: clean fclean all