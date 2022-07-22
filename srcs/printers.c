/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:44 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/22 10:49:36 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	node_print(t_node *node)
{
	t_node	*ptr;

	ptr = node;
	while (ptr)
	{
		printf("%-15s", ptr->file_name);
		ptr = ptr->next;
	}
	printf("\n");
}

static void	list_print(t_node *file_node, size_t *blocks)
{
	t_column	*column;

	if (file_node)
		printf("total %i\n", (int)blocks[0]);
	column = attr_col(file_node);
	while (file_node)
	{
		printf("%c", file_node->file_type);
		printf("%s  ", file_node->permission);
		printf("%*i ", column->links_len, file_node->links);
		printf("%*s  ", column->owner_name_len, file_node->owner_name);
		printf("%*s  ", column->owner_group_len, file_node->owner_group);
		printf("%*i ", column->file_size_len, file_node->size);
		printf("%s ", file_node->date);
		printf("%s", file_node->file_name);
		printf("\n");
		file_node = file_node->next;
	}
	free(column);
}

void	print(t_node *node, t_cont *cont)
{	
	char	*path;

	path = NULL;
	if (cont->opt->lis)
		list_print(node, &cont->blocks);
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
					printf("\n%s:\n", path);
					ft_ls((const char *)path, cont->opt);
					free(path);
				}
			}
			node = node->next;
		}
	}
}
