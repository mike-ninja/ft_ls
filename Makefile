# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 11:22:02 by mbarutel          #+#    #+#              #
#    Updated: 2022/07/21 15:34:42 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

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
SRC_FILE 	+= utils
SRC_FILE 	+= printers
SRC_FILE 	+= column_attr



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
	@$(CC) -c $(FLAGS) $(SRC)
	@echo "$(CYAN)Compiled obj files$(RESET)"
	@$(CC) -o $(NAME) $(LIB_INC) $(OBJ)
	@echo "$(GREEN)Compiled ft_ls$(RESET)"

clean:
	@echo "$(RED)Cleaning obj files$(RESET)"
	@rm -f $(OBJ)

fclean:	clean
	@echo "$(PURPLE)Cleaning ft_ls$(RESET)"
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re