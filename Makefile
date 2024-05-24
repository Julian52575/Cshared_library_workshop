##
## EPITECH PROJECT, 2024
## myteams
## File description:
## build the ftp lib
##
YEL=\033[1;33m
GRN='\033[0;32m'
RED='\033[0;31m'
NC=\033[0m # No Color

NAME 		=	liblinked.so

SRC_DIR 	=	src
SRC_FILES 	=	linkedhandler_create.c \
			linkedhandler_manage_node.c
SRC_PATH	=	$(patsubst %,$(SRC_DIR)/%,$(SRC_FILES))

OBJ_DIR 	= 	obj
OBJ_FILES 	=	$(patsubst %.c,%.o,$(SRC_FILES))
OBJ_DIR_FILES	=	$(patsubst %,$(OBJ_DIR)/%,$(OBJ_FILES))

CFLAGS 		=	-Wall -Wextra
INCLUDES 	=	-iquote./includes/

#build the object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo -e "$(YEL)\tBuilding $@...$(NC)"
	gcc -c -o $@ $< $(CFLAGS) $(INCLUDES)

all: $(OBJ_DIR_FILES)
	@gcc -shared -fPIC $(OBJ_DIR)/*.o -o $(NAME)
	@echo -e "$(GRN)\t$(NAME) done!$(NC)"

clean:
	@echo -e "$(YEL)\tCleaning object files...$(NC)"
	@rm obj/*.o || true

fclean: clean
	@echo -e "$(YEL)\tCleaning $(NAME)...$(NC)"
	@rm $(NAME) || true

re: fclean all

tests_run: re
	./tests/tests_run.sh

.Phony: all clean fclean re
