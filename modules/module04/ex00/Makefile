NAME = Polymorphism
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = $(shell ls *.cpp)
OBJ = $(SRCS:.cpp=.o)
HEADER = $(shell ls *hpp)

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
