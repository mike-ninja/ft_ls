/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:44 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/28 15:57:20 by mbarutel         ###   ########.fr       */
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

static int	node_size(t_node *node)
{
	int	ret;

	ret = 0;
	while (node)
	{
		ret++;
		node = node->next;
	}
	return (ret);
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
	if (column->name_len > 10)
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

static void	list_print(t_node *file_node, t_col *column)
{
	while (file_node)
	{
		ft_printf("%c", file_node->file_type);
		ft_printf("%s", file_node->permission);
		ft_printf("%c ", file_node->extra_attr);
		ft_printf("%*i ", column->links_len, file_node->links);
		ft_printf("%-*s  ", column->owner_name_len, file_node->owner_name);
		ft_printf("%-*s  ", column->owner_group_len, file_node->owner_group);
		ft_printf("%*i ", column->file_size_len, file_node->size);
		ft_printf("%s ", file_node->date[0]);
		ft_printf("%*s ", column->date_len, file_node->date[1]);
		ft_printf("%s", file_node->file_name);
		if (file_node->links_to)
			ft_printf(" -> %s", file_node->links_to);
		ft_printf("\n");
		file_node = file_node->next;
	}
}

void	print(t_node *node, t_cont *cont)
{	
	char	*path;
	t_col	*column;

	path = NULL;
	column = attr_col(node);
	if (cont->opt->lis)
		list_print(node, column);
	else
		node_print(node, column);
	free(column);
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
