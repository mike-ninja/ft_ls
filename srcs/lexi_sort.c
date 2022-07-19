/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexi_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:41:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/19 10:51:54 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

// static void array_read_before_sort(t_array *arr)
// {
// 	size_t i;

// 	i = 0;
// 	while (i < arr->index)
// 	{
// 		printf("%s\n", arr->arr[i]);
// 		i++;
// 	}
// }

static void	str_swap(char **array, size_t i, size_t y)
{
	char	*ptr;

	ptr = array[i];
	array[i] = array[y];
	array[y] = ptr;
}

static t_node	*node_match(char *arr, t_node *node)
{
	t_node *ptr;

	ptr = node;
	while(ft_strcmp(ptr->file_name, arr) != 0)
		ptr = ptr->next;
	return(ptr);
}

void	date_sort(t_array *arr, t_opts *opt, t_node *node)
{
	size_t	i;
	size_t	y;
	t_node	*ptr1;
	t_node	*ptr2;

	i = 0;	
	while (i < arr->index)
	{
		ptr1 = node_match(arr->arr[i], node);
		y = 0;
		while (y < arr->index)
		{
			ptr2 = node_match(arr->arr[y], node);
			if (opt->rev)
			{
				if (ptr1->s_date.tv_sec < ptr2->s_date.tv_sec)
				{
					str_swap(arr->arr, i, y);
				}
				if (ptr1->s_date.tv_sec == ptr2->s_date.tv_sec)
				{
					if ((ft_strcmp(arr->arr[i], arr->arr[y])) > 0)
						str_swap(arr->arr, i, y);
				}
				ptr1 = node_match(arr->arr[i], node);
			}
			else
			{
				if (ptr1->s_date.tv_sec > ptr2->s_date.tv_sec)
				{
					str_swap(arr->arr, i, y);
				}
				if (ptr1->s_date.tv_sec == ptr2->s_date.tv_sec)
				{
					if ((ft_strcmp(arr->arr[i], arr->arr[y])) < 0)
						str_swap(arr->arr, i, y);
				}
				ptr1 = node_match(arr->arr[i], node);
			}
			y++;
		}
		i++;
	}
}

/*
	Sorts the array in lexicographic order and
	will sort itin reverse if -r flag is valid
*/
void	lexi_sort(t_array *arr, t_opts *opt)
{
	size_t	i;
	size_t	y;
	int		ret;

	i = 0;
	ret = 0;
	while (i < arr->index)
	{
		y = 0;
		while (y < arr->index)
		{
			ret = ft_strcmp((char *)arr->arr[i], (char *)arr->arr[y]);
			if (opt->rev)
			{
				if (ret > 0)
					str_swap(arr->arr, i, y);
			}
			else
				if (ret < 0)
					str_swap(arr->arr, i, y);
			y++;
		}
		i++;
	}
}

static t_node	*array_size(t_node *file_node, t_opts *opt, size_t *index)
{
	t_node	*head;

	head = file_node;
	while (file_node)
	{
		index[0]++;
		if (!opt->all && *file_node->file_name == '.')	
			index[0]--;
		file_node = file_node->next;
	}
	return (head);
}

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
	// array_read_before_sort(ret);
	lexi_sort(ret, opt);
	if (opt->tim)
		date_sort(ret, opt, file_node);
	return (ret);
}
