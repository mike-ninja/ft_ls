/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/27 10:54:51 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	swap_init(t_swap *swap, t_node *node, t_node *file_node)
{
	swap->prev = NULL;
	swap->head = file_node;
	swap->node = node;
	swap->f_node = file_node;
}

static t_node	*node_connect(t_node *nd, t_node *f_nd,
	t_cont *cont, struct stat *st)
{
	t_swap			swap[1];

	swap_init(swap, nd, f_nd);
	if (!swap->node)
		node_collect_util(swap->f_node, st, cont);
	else
	{
		node_collect_util(swap->node, st, cont);
		while (swap->f_node)
		{
			if (cont->opt->tim)
			{
				if (date_sort(swap, cont))
					return (swap->head);
			}
			else
				if (lexi_sort(swap, cont))
					return (swap->head);
			swap->prev = swap->f_node;
			swap->f_node = swap->f_node->next;
		}
		if (!swap->f_node)
			swap->prev->next = swap->node;
	}
	return (swap->head);
}

t_node	*file_node_collect(t_node *node, t_node *file_node, t_cont *cont)
{
	char		*path;
	struct stat	*stat;

	path = get_path(cont->dir_name, cont->file_name);
	stat = malloc(sizeof(struct stat));
	if (!stat)
	{
		ft_printf("ft_ls: %s: Not enough memory\n", cont->file_name);
		exit(EXIT_FAILURE);
	}
	if (lstat(path, stat) < 0)
	{
		ft_printf("ft_ls: %s: No such file or directory\n", cont->file_name);
		exit(EXIT_FAILURE);
	}
	free(path);
	return (node_connect(node, file_node, cont, stat));
}

t_node	*linked_list(t_node *file_node, t_cont *cont)
{
	t_node	*node;

	node = NULL;
	if (!file_node)
	{
		file_node = (t_node *)malloc(sizeof(t_node));
		if (!file_node)
			return (NULL);
		file_node_init(file_node);
		file_node = file_node_collect(node, file_node, cont);
	}
	else
	{
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
		{
			nodes_array_delete(file_node);
			ft_printf("ft_ls: %s: Not enough memory\n", cont->file_name);
			exit(EXIT_FAILURE);
		}
		file_node_init(node);
		file_node = file_node_collect(node, file_node, cont);
	}
	return (file_node);
}
