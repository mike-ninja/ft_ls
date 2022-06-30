# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 11:34:58 by mbarutel          #+#    #+#              #
#    Updated: 2022/06/28 11:41:38 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= libftprintf.a
LIBFT		= libft
INCLUDE		= incs
SRC_DIR		= srcs/
OBJ_DIR		= objs/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
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

SRC_FILES    =    ft_arg_filter
SRC_FILES    +=    ft_char_convert
SRC_FILES    +=    ft_printers
SRC_FILES    +=    ft_diouxf_convert
SRC_FILES    +=    ft_colouring
SRC_FILES    +=    ft_printf
SRC_FILES    +=    ft_str_convert
SRC_FILES    +=    ft_utils
SRC_FILES    +=    ft_bonus_func

SRC         =     $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ         =     $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF        =    .cache_exists

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:	clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

libft:
	@make re -C $(LIBFT)

.PHONY:	all clean fclean re norm