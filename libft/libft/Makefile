# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 14:58:30 by mbarutel          #+#    #+#              #
#    Updated: 2021/12/13 23:01:35 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 		= libft.a
INCLUDE		= incs
SRC_DIR		= srcs/
OBJ_DIR		= objs/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources

SRCS_FILES 	= ft_memset 
SRCS_FILES += ft_bzero
SRCS_FILES += ft_memcpy
SRCS_FILES += ft_memccpy
SRCS_FILES += ft_memmove
SRCS_FILES += ft_memchr
SRCS_FILES += ft_memcmp
SRCS_FILES += ft_strlen
SRCS_FILES += ft_strdup
SRCS_FILES += ft_strcpy
SRCS_FILES += ft_strncpy
SRCS_FILES += ft_strcat
SRCS_FILES += ft_strncat
SRCS_FILES += ft_strlcat
SRCS_FILES += ft_strchr
SRCS_FILES += ft_strrchr
SRCS_FILES += ft_strstr
SRCS_FILES += ft_strnstr
SRCS_FILES += ft_strcmp
SRCS_FILES += ft_strncmp
SRCS_FILES += ft_atoi
SRCS_FILES += ft_isalpha
SRCS_FILES += ft_isdigit
SRCS_FILES += ft_isalnum
SRCS_FILES += ft_isascii
SRCS_FILES += ft_isprint
SRCS_FILES += ft_toupper
SRCS_FILES += ft_tolower
SRCS_FILES += ft_memalloc
SRCS_FILES += ft_memdel
SRCS_FILES += ft_strnew
SRCS_FILES += ft_strdel
SRCS_FILES += ft_strclr
SRCS_FILES += ft_striter
SRCS_FILES += ft_striteri
SRCS_FILES += ft_strmap
SRCS_FILES += ft_strmapi
SRCS_FILES += ft_strequ
SRCS_FILES += ft_strnequ
SRCS_FILES += ft_strsub
SRCS_FILES += ft_strjoin
SRCS_FILES += ft_strtrim
SRCS_FILES += ft_strsplit
SRCS_FILES += ft_itoa
SRCS_FILES += ft_putchar
SRCS_FILES += ft_putstr
SRCS_FILES += ft_putendl
SRCS_FILES += ft_putnbr
SRCS_FILES += ft_putchar_fd
SRCS_FILES += ft_putstr_fd
SRCS_FILES += ft_putendl_fd
SRCS_FILES += ft_putnbr_fd
SRCS_FILES += ft_lstnew
SRCS_FILES += ft_lstdelone
SRCS_FILES += ft_lstdel
SRCS_FILES += ft_lstadd
SRCS_FILES += ft_lstaddback
SRCS_FILES += ft_lstiter
SRCS_FILES += ft_lstmap
SRCS_FILES += ft_del
SRCS_FILES += ft_calloc
SRCS_FILES += ft_strlcpy
SRCS_FILES += ft_lstlast
SRCS_FILES += ft_lstsize
SRCS_FILES += ft_itoa_base
SRCS_FILES += ft_ltoa_base
SRCS_FILES += ft_lltoa_base
SRCS_FILES += ft_ulltoa_base
SRCS_FILES += ft_ftoa
SRCS_FILES += ft_lftoa

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS_FILES)))

OBJF 		= .cache_exists

#####

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)LIBFT Complete$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	
clean:
	@rm -f $(OBJ)
	@echo "$(RED)OBJ Files Cleaned$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)LIBFT Cleaned$(DEF_COLOR)"
	
re: fclean all