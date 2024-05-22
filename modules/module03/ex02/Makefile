NAME = ScavTrap
SRCS = ${shell ls *.cpp}
HEADERS = ${shell ls *.hpp}
OBJS = (SRCS:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)

%.o: %.cpp $(HEADERS)
	c++ $(FLAGS) -c $< -o $@
$(NAME):$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re: fclean all