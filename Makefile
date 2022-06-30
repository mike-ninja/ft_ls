# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 11:22:02 by mbarutel          #+#    #+#              #
#    Updated: 2022/06/30 12:11:02 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 		= ft_ls
SRC_DIR		= srcs/
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
LIB_INC		= -Llibft -lftprintf

# Files

SRC_FILE 	= ft_ls

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