/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:44 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/12 12:00:44 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	line_print(t_node *node, int row, int width, int max_row)
{
	t_node	*ptr;
	int		index;

	index = 0;
	ptr = node;
	while (index++ < row)
		ptr = ptr->next;
	while (ptr)
	{
		index = 0;
		ft_printf("%-*s", width, ptr->file_name);
		while (index++ < max_row)
		{
			if (ptr)
				ptr = ptr->next;
			else
				ptr = NULL;
		}
		if (!ptr)
			break ;
	}
}


static void	node_print(t_node *node, t_col *column)
{
	int				i;
	int				lst_len;
	struct winsize	argp;
	int				width;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &argp);
	lst_len = node_size(node);
	width = 8;
	if (column->name_len > 7)
		width = 16;
	if (column->name_len > 16)
		width = 24;
	column->norm_col = argp.ws_col / width;
	column->norm_row = lst_len / column->norm_col;
	if ((lst_len % column->norm_col) != 0)
		column->norm_row++;
	i = -1;
	while (++i < column->norm_row)
	{
		line_print(node, i, width, column->norm_row);
		ft_printf("\n");
	}
}

static void	list_print(t_node *node, t_col *col)
{
	while (node)
	{
		ft_printf("%c", node->file_type);
		ft_printf("%s", node->permission);
		ft_printf("%c ", node->extra_attr);
		ft_printf("%*i ", col->links_len, node->links);
		ft_printf("%-*s  ", col->owner_name_len, node->owner_name);
		ft_printf("%-*s  ", col->owner_group_len, node->owner_group);
		if (node->file_type == 'c' || node->file_type == 'b')
			rdev_print(node, col);
		else
			ft_printf("%*i ", col->file_size_len, node->size);
		ft_printf("%s ", node->date[0]);
		ft_printf("%*s ", col->date_len, node->date[1]);
		ft_printf("%s", node->file_name);
		if (node->links_to)
			ft_printf(" -> %s", node->links_to);
		ft_printf("\n");
		node = node->next;
	}
}

static void	print_utils(t_node *node, t_cont *cont)
{
	t_col	*column;

	column = attr_col(node);
	if (cont->opt->lis)
		list_print(node, column);
	else
		node_print(node, column);
	free(column);
}

void	print(t_node *node, t_cont *cont)
{	
	char	*path;

	path = NULL;
	print_utils(node, cont);
	if (cont->opt->rec)
	{
		while (node)
		{
			if (node->file_type == 'd')
			{
				if ((ft_strcmp(node->file_name, ".")) != 0
					&& (ft_strcmp(node->file_name, "..")) != 0)
				{
					path = get_path(cont->dir_name, node->file_name);
					ft_printf("\n%s:\n", path);
					ft_ls((const char *)path, cont->opt);
					free(path);
				}
			}
			node = node->next;
		}
	}
}
