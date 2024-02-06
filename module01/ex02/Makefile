SRCS = $(wildcard *.cpp)
NAME = hithisisbrain
CC = c++
FLAGS = -Wextra -Wall -Werror -std=c++11
AR = ar rcs
OBJ = $(SRCS:.cpp=.o)
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re