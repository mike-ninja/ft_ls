/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:56:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/25 11:16:20 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

// Forbidden
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

# define OPTIONS "Ralrt"

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
	char				file_type;
	char				*permission;
	unsigned int		links;
	char				*owner_name;
	char				*owner_group;
	unsigned int		size;
	char				*date;
	struct timespec		s_date;
	char				*file_name;
	char				*links_to;
	struct file_node	*next;
}				t_node;

typedef struct swap_struct
{
	t_node	*head;
	t_node	*node;
	t_node	*f_node;
	t_node	*prev;
}				t_swap;

typedef struct column_attr
{
	int	links_len;
	int	owner_name_len;
	int	owner_group_len;
	int	file_size_len;
}				t_col;

typedef struct container
{
	char	*file_name;
	char	*dir_name;
	size_t	blocks;
	t_opts	*opt;
}				t_cont;

// ft_ls
t_node	*ft_ls(const char *file_name, t_opts *opt);

// Options
void	init_struct(t_opts *opt);
void	options_parse(t_opts *opt, char *opt_str);

// Utils
char	*get_path(char *input, char *file_name);
int		file_type(mode_t mode);
char	*permission_str(mode_t mode);
char	*get_owner_name(uid_t uid);
char	*get_owner_group(gid_t gid);
char	*last_modification_date(struct timespec mtimespec);

// Printers
void	print(t_node *node, t_cont *cont);

// Node Funcs
t_node	*file_node_collect(t_node *node, t_node *file_node, t_cont *cont);
t_node	*linked_list(t_node *file_node, t_cont *cont);

// Column Attributes
t_col	*attr_col(t_node *nodes);

// Linked list utils
void	nodes_array_delete(t_node *file_node);
void	node_collect_util(t_node *nd, struct stat *st, t_cont *cont);
void	file_node_init(t_node *node);

// Linked list sort
bool	date_insert(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev);
bool	date_insert_rev(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev);
bool	lexi_sort(t_swap *swap, t_cont *cont);
bool	date_sort(t_swap *swap, t_cont *cont);

#endif