/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:56:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/20 12:57:55 by mbarutel         ###   ########.fr       */
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
	// struct file_node	*prev; // Testing
	char				file_type;
	char				*permission;
	unsigned int		links;
	char				*owner_name;
	char				*owner_group;
	unsigned int		size;
	char				*date;
	struct timespec		s_date;
	char				*file_name;
	struct file_node	*next;
}				t_node;

typedef struct	lexi_array
{
	char	**arr;
	size_t	index;
}				t_array;

typedef struct	column_attr
{
	int	links_len;
	int	owner_name_len;
	int	owner_group_len;
	int	file_size_len;
}				t_column;

// ft_ls
t_node	*ft_ls(const char *file_name, t_opts *opt);

// Options
void	init_struct(t_opts *opt);
void    options_parse(t_opts *opt, char *opt_str);

// Utils
char    *get_path(char *input, char *file_name);
int		file_type(mode_t mode);
char    *permission_str(mode_t mode);
char    *get_owner_name(uid_t uid);
char    *get_owner_group(gid_t gid);
char    *last_modification_date(struct timespec mtimespec);

// Options functions
void    recursive(char *file_name, t_node *file_node, t_opts *opt);

// Lexi Sorting
t_array *file_name_array_collect(t_node *file_node, t_opts *opt);

// Printers
void	list_print(t_node *file_node, size_t *blocks);
void    standard_print(t_array *array);

// Node Funcs
void	nodes_array_delete(t_node *file_node);
t_node	*file_node_collect(const char *prefix_file_name, t_node *node, t_node *file_node, char *file_name, size_t *blocks, t_opts *opt);
void	file_node_init(t_node *node);
t_node	*file_nodes_array(const char *prefix_file_name, t_node *file_node, char *file_name, size_t *blocks, t_opts *opt);

// Column Attributes
t_column	*attr_col(t_node *nodes);

#endif