/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:01:50 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/20 13:03:36 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_array	*file_name_array_collect(t_node *file_node, t_opts *opt)
{
	size_t	index[1];
	t_array	*ret;
	t_node  *ptr;

	index[0] = 0;
	ret = (t_array *)malloc(sizeof(t_array));
	if (!ret)
		return (NULL);
	ptr = array_size(file_node, opt, index);
	ret->arr = (char **)malloc(sizeof(char *) * index[0]);
	if (!ret->arr)
		return (NULL);
	index[0] = 0;
	while (ptr)
	{
		while (!opt->all && *ptr->file_name == '.')
			ptr = ptr->next;
		ret->arr[index[0]++] = ptr->file_name;
		ptr = ptr->next;
	}
	ret->index = index[0];
	// // array_read_before_sort(ret);
	// lexi_sort(ret, opt);
	// if (opt->tim)
	// 	date_sort(ret, opt, file_node);
	return (ret);
}