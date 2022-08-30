/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:44 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/30 10:40:20 by mbarutel         ###   ########.fr       */
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
	int				width;
	int				lst_len;
	struct winsize	arginp;
	struct winsize	argout;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &arginp);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &argout);
	lst_len = node_size(node);
	width = get_width(column->name_len);
	column->norm_col = arginp.ws_col / width;
	if (column->norm_col && (arginp.ws_col == argout.ws_col))
	{
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
	else
		line_print_nw(node);
}

static t_node	*list_print(t_node *node, t_col *col)
{
	t_node	*prev;
	t_node	*head;

	prev = NULL;
	head = NULL;
	while (node)
	{
		ft_printf("%c%s", node->file_type, node->permission);
		ft_printf("%c %*i ", node->extra_attr, col->links_len, node->links);
		ft_printf("%-*s  ", col->owner_name_len, node->owner_name);
		ft_printf("%-*s  ", col->owner_group_len, node->owner_group);
		if (node->file_type == 'c' || node->file_type == 'b')
			rdev_print(node, col);
		else
			ft_printf("%*i ", col->file_size_len, node->size);
		ft_printf("%s %*s ", node->date[0], col->date_len, node->date[1]);
		ft_printf("%s", node->file_name);
		if (node->links_to)
			ft_printf(" -> %s", node->links_to);
		ft_printf("\n");
		node = delete_node(node, &prev, &head);
	}
	return (head);
}

static t_node	*print_utils(t_node *node, t_cont *cont)
{
	t_col	*column;

	column = attr_col(node, cont->opt);
	if (cont->opt->lis)
		node = list_print(node, column);
	else
		node_print(node, column);
	free(column);
	return (node);
}

t_node	*print_nodes(t_node *node, t_cont *cont)
{	
	char	*path;
	t_node	*head;

	path = NULL;
	node = print_utils(node, cont);
	head = node;
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
	return (head);
}
