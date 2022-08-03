# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 11:22:02 by mbarutel          #+#    #+#              #
#    Updated: 2022/08/03 13:02:18 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

LIBFT		= libft
NAME 		= ft_ls
SRC_DIR		= srcs/
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
LIB_INC		= -Llibft -lftprintf

# Files

SRC_FILE 	= main
SRC_FILE 	+= options
SRC_FILE 	+= linked_list
SRC_FILE 	+= linked_list_utils
SRC_FILE 	+= linked_list_sort
SRC_FILE 	+= utils_one
SRC_FILE 	+= utils_two
SRC_FILE 	+= printers
SRC_FILE 	+= column_attr
SRC_FILE 	+= extra_attr
SRC_FILE 	+= multiple_args
SRC_FILE 	+= multiple_args_util

# Colours

RED = \033[1;31m
GREEN = \033[1;32m
PURPLE = \033[1;35m
CYAN = \033[1;36m
RESET = \033[0m

# Variables

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))
OBJ			= $(addsuffix .o, $(SRC_FILE))

# Targets

all: $(NAME)

$(NAME): $(SRC)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC)
	@echo "$(CYAN)Compiled obj files$(RESET)"
	@$(CC) -o $(NAME) $(LIB_INC) $(OBJ)
	@echo "$(GREEN)Compiled ft_ls$(RESET)"

clean:
	@make clean -C $(LIBFT)
	@echo "$(RED)Cleaning obj files$(RESET)"
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C $(LIBFT)
	@echo "$(PURPLE)Cleaning ft_ls$(RESET)"
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re