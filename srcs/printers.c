/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:44 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/15 16:02:23 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	list_print(t_node *file_node, t_opts *opt, t_array *lexi_sorted, size_t *blocks)
{
	size_t	    i;
	t_node	    *ptr;
	char	    *perm;
    t_column    *column;

	i = 0;
	perm = NULL;
	printf("total %i\n", (int)blocks[0]);
    column = attr_col(file_node);
	while (i < lexi_sorted->index)
	{
		ptr = file_node;
		while (ptr)
		{
			if (ft_strcmp(lexi_sorted->arr[i], ptr->file_name) == 0)
			{
				printf("%c", ptr->file_type);
				printf("%s  ", ptr->permission);
				printf("%*i ", column->links_len, ptr->links);
				printf("%*s  ", column->owner_name_len, ptr->owner_name);
				printf("%*s  ", column->owner_group_len, ptr->owner_group);
				printf("%*i ", column->file_size_len, ptr->size);
				printf("%s ", ptr->date);
				printf("%s", ptr->file_name);
				printf("\n"); 
				break ;
			}
			ptr = ptr->next;
		}
		i++;
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