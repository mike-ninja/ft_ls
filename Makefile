# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 11:22:02 by mbarutel          #+#    #+#              #
#    Updated: 2022/07/01 12:42:10 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 		= ft_ls
SRC_DIR		= srcs/
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
LIB_INC		= -Llibft -lftprintf

# Files

SRC_FILE	= main
SRC_FILE 	+= ft_ls
SRC_FILE 	+= utils

# Variables

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))
OBJ			= $(addsuffix .o, $(SRC_FILE))

# Targets

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) -c $(SRC)
	@$(CC) -o $(NAME) $(LIB_INC) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re