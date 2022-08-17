/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:56:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/17 13:48:38 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

// Header
# include    "../libft/incs/ft_printf.h"

// Directory metadata reading
# include    <dirent.h>

// Standard
# include	<stdlib.h>
# include   <stdbool.h>
# include	<time.h>
# include	<errno.h>

// File metadata reading
# include	<sys/stat.h>
# include	<pwd.h>
# include	<grp.h>
# include	<sys/acl.h>
# include	<sys/xattr.h>

// Terminal window size
# include	<sys/ioctl.h>

# define OPTIONS "-Ralrt"
# define SIX_MONTHS 15778476

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
	char				extra_attr;
	unsigned int		links;
	char				*owner_name;
	char				*owner_group;
	unsigned int		size;
	unsigned int		major;
	unsigned int		minor;
	char				**date;
	time_t				s_date;
	time_t				n_date;
	char				*file_name;
	char				*links_to;
	struct file_node	*next;
}				t_node;

typedef struct swap_struct
{
	t_node	*head;
	t_node	*node;
	t_node	*ptr;
	t_node	*prev;
}				t_swap;

typedef struct column_attr
{
	int				norm_col;
	int				norm_row;
	int				links_len;
	int				owner_name_len;
	int				owner_group_len;
	int				date_len;
	int				file_size_len;
	int				major_len;
	int				minor_len;
	int				name_len;
	struct winsize	*argp;
}				t_col;

typedef struct container
{
	char	*file_name;
	char	*dir_name;
	char	*path;
	size_t	blocks;
	t_opts	*opt;
}				t_cont;

typedef struct args
{
	char	*file_name;
	time_t	modi_date;
}				t_args;

// Main
void	ft_ls(const char *arg, t_opts *opt);

// Options
void	init_struct(t_opts *opt);
void	options_parse(t_opts *opt, char *opt_str);
int		node_size(t_node *node);

// Utils
void	attr_struct_init(t_col *attr);
int		file_type(mode_t mode);
char	*get_path(char *input, char *file_name);
char	*permission_str(mode_t mode);
char	*get_owner_name(uid_t uid);
char	*get_owner_group(gid_t gid);
char	**last_modification_date(struct timespec mtimespec);
char	*permission_bits(mode_t mode);
void	cont_init(t_cont *cont, t_opts *opt);
void	file_node(t_node **node, char *f_name, t_cont *cont);
void	ft_error(char *arg, int err_num);

// Printers
void	print(t_node *node, t_cont *cont);

// Linked list
t_node	*node_collect(t_node *node, t_node *file_node, t_cont *cont);
t_node	*linked_list(t_node *head, t_cont *cont);
void	nodes_array_delete(t_node *file_node);
void	node_collect_util(t_node *nd, struct stat *st, t_cont *cont);
void	file_node_init(t_node *node);
bool	date_insert(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev);
bool	date_insert_rev(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev);
bool	lexi_sort(t_swap *swap, t_cont *cont);
bool	date_sort(t_swap *swap, t_cont *cont);

// Column Attributes
t_col	*attr_col(t_node *nodes);
void	len_correction(t_col *attr);
void	major_len(t_node *node, t_col *attr);
void	minor_len(t_node *node, t_col *attr);
void	rdev_print(t_node *node, t_col *col);

// Bonus
char	extra_attribute(char *dir_name, char *file_name);

// Multiple Arguments
void	arg_parse(int index, int ac, char **av, t_opts *opt);
void	args_del(t_args *args, int index);
void	args_lexi_swap(int i, int y, t_args *args, t_opts *opt);
void	args_date_swap(int i, int y, t_args *args, t_opts *opt);
void	args_sorting(int index, t_args *args, t_opts *opt);
void	collect_dates(int index, t_args *args);

#endif