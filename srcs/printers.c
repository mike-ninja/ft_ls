/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:44 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 11:37:36 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	node_print(t_node *node)
{
	t_node *ptr;

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
    t_column    *column;

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

// void    standard_print(t_array *array)
// {
//     size_t i;

//     i = 0;
//     while (i < array->index)
//     {
//         printf("%-15s", array->arr[i]);
//         i++;
//     }
// }

void	print(t_node *node, t_opts *opt, size_t *blocks, char *file_name)
{	
	char *path;

	path = NULL;
	if (opt->lis)
		list_print(node, blocks);
	else
		node_print(node);
	if (opt->rec)
	{
		while (node)
		{
			if (node->file_type == 'd')
			{
				path = get_path(file_name, node->file_name);
				printf("\n%s:\n", path);
				ft_ls((const char *)path, opt);
				free(path);
			}
			node = node->next;
		}
		
	}
}