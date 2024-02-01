SRC_DIR = src/
INC_DIR = inc/

SRCS = $(wildcard $(SRC_DIR)*.cpp)
INCS = $(wildcard $(INC_DIR)*.hpp)
NAME = brainz
CC = c++
FLAGS = -Wextra -Wall -Werror -std=c++98
AR = ar rcs
OBJ = $(SRCS:.cpp=.o)
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I$(INC_DIR) $(OBJ) -o $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re