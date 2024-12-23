NAME = Form
SRC = $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
FLAGS =  -std=c++98
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