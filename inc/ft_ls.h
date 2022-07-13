/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:56:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/13 11:32:38 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

// Forbidden
# include    <stdio.h>
# include    <string.h>
// Forbidden

// Header
# include    "../libft/incs/ft_printf.h"

// Directory metadata reading
# include    <dirent.h>

// File metadata reading
# include    <sys/stat.h>
# include    <stdlib.h>
# include    <sys/types.h>
# include    <pwd.h>
# include    <grp.h>
# include    <uuid/uuid.h>
# include    <time.h>

// Bool data type
# include    <stdbool.h>

typedef struct options
{
	bool	lis;
	bool	all;
	bool	rev;
	bool	tim;
	bool	rec;
}				t_opts;

typedef struct file_node
{
	struct file_node	*current; // maybe we don't need
	char	*file_name;
	char	file_type;
	struct file_node	*next;
}				t_node;

// Prototypes
// void    ft_ls(const char *file_name, t_opts *opt);

// Options
void	init_struct(t_opts *opt);
void    options_parse(t_opts *opt, char *opt_str);

// Linked list
t_node  *file_name_list(const char *file_name, t_opts *opt);

// Utils
char    *get_path(char *input, char *file_name);
int file_type(mode_t mode);
#endif