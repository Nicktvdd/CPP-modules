NAME = materias

INC_DIR = inc/

TEST1 = test1
TEST2 = test2

SRC = src/AMateria.cpp src/Character.cpp src/Cure.cpp src/Ice.cpp src/MateriaList.cpp \
src/MateriaSource.cpp src/main.cpp
SRC2 = src/AMateria.cpp src/Character.cpp src/Cure.cpp src/Ice.cpp src/MateriaList.cpp \
src/MateriaSource.cpp src/main2.cpp
SRC3 = src/AMateria.cpp src/Character.cpp src/Cure.cpp src/Ice.cpp src/MateriaList.cpp \
src/MateriaSource.cpp src/main3.cpp

OBJ = $(SRC:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++11
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m


all: $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(FLAGS) -I$(INC_DIR) $(OBJ) -o $(NAME)
		@echo "$(GREEN)The binary was created successfully$(NC)"

$(TEST1) : $(OBJ2)
		@$(CC) $(FLAGS) $(OBJ2) -o $(TEST1)
		@echo "$(GREEN)The binary was created successfully$(NC)"

$(TEST2) : $(OBJ3)
		@$(CC) $(FLAGS) -I$(INC_DIR) $(OBJ3) -o $(TEST2)
		@echo "$(GREEN)The binary was created successfully$(NC)"

%.o: %.cpp
		@$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@
		@echo "$(GREEN)Object file created.$(NC)"

clean:
		@rm -f $(OBJ) $(OBJ2) $(OBJ3)
		@echo "$(RED)Object files deleted$(NC)"

fclean: clean
		@rm -rf $(NAME) $(TEST1) $(TEST2)
		@echo "$(RED)The binary was deleted successfully$(NC)"

re: fclean all

