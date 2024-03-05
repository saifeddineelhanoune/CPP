NAME = LMS
SRC = $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
HEADER = $(shell ls *.hpp)
FLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

%.o: %.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@
$(NAME): $(OBJ) $(HEADER)
	c++ $(FLAGS) $(OBJ) $(HEADER) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(NAME)
re: clean fclean