##
## EPITECH PROJECT, 2023
## mars_lib
## File description:
## Makefile
##

PROJECT_NAME			=	mars_lib
NAME					:=	libmars.a

DIR_PRINTF				:=	my_printf
DIR_STDLIB				:=	my_stdlib
DIR_MINILINKEDLIST		:=	mini_linked_list

BUILD_DIR				:=	build

all:
	@$(MAKE) -s -C $(DIR_STDLIB)
	@$(MAKE) -s -C $(DIR_PRINTF)
	@$(MAKE) -s -C $(DIR_MINILINKEDLIST)
	@$(MAKE) -s $(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)\
	&& echo -e "\033[1;32m[SPACESHIP READY]\033[0m" $(NAME)\
	|| echo -e "\033[1;31m[SPACESHIP CRASHED]\033[0m" $(NAME)

OBJ = $(shell find $(DIR_PRINTF)/$(BUILD_DIR) -name '*.o' -type f)
OBJ += $(shell find $(DIR_STDLIB)/$(BUILD_DIR) -name '*.o' -type f)
OBJ += $(shell find $(DIR_MINILINKEDLIST)/$(BUILD_DIR) -name '*.o' -type f)

debug:
	@$(MAKE) -s -C $(DIR_STDLIB) debug
	@$(MAKE) -s -C $(DIR_PRINTF) debug
	@$(MAKE) -s -C $(DIR_MINILINKEDLIST) debug
	@$(MAKE) -s $(NAME)

clean:
	@make -s -C my_stdlib/ clean
	@make -s -C my_printf/ clean
	@make -s -C mini_linked_list/ clean
	@echo -e "\033[1;31m[DELETED]\033[0m" $(BUILD_DIR)

fclean:
	@make -s -C my_stdlib/ fclean
	@make -s -C my_printf/ fclean
	@make -s -C mini_linked_list/ fclean
	@rm -f $(NAME)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(NAME)

re:	fclean all

tests_run:
	@make -s -C my_stdlib/ tests_run
	@make -s -C my_printf/ tests_run
	@make -s -C mini_linked_list/ tests_run
	gcovr --exclude tests/

.PHONY: all clean fclean re debug

.SILENT: all $(NAME) clean fclean re debug

%:
	@echo -e "\033[1;31m[ERROR]\033[0m" "No rule to make target '$@'"
