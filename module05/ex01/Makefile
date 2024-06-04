NAME = form

SRC = main.cpp	\
Bureaucrat.cpp	\
Form.cpp

OBJ = $(addprefix obj/,$(SRC:%.cpp=%.o))

DEP = $(OBJ:%.o=%.d)

#folders
OBJ_DIR = ./obj

#flags
WWW = -Wall -Wextra -Werror
FLAGS = $(WWW) -std=c++11

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

-include $(DEP)

$(OBJ_DIR)/%.o: %.cpp
	c++ $(FLAGS) -MMD -c $< -o $@

re: fclean all