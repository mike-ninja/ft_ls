/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:44 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/27 10:49:01 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	node_print(t_node *node)
{
	t_node	*ptr;

	ptr = node;
	while (ptr)
	{
		ft_printf("%-15s", ptr->file_name);
		ptr = ptr->next;
	}
	ft_printf("\n");
}

static void	list_print(t_node *file_node)
{
	t_col	*column;

	column = attr_col(file_node);
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
	free(column);
}

void	print(t_node *node, t_cont *cont)
{	
	char	*path;

	path = NULL;
	if (cont->opt->lis)
		list_print(node);
	else
		node_print(node);
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
