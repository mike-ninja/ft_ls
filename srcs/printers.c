/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:44 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/19 15:37:13 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	list_print(t_node *file_node, size_t *blocks)
{
    t_column    *column;

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

void    standard_print(t_array *array)
{
    size_t i;

    i = 0;
    while (i < array->index)
    {
        printf("%-15s", array->arr[i]);
        i++;
    }
}