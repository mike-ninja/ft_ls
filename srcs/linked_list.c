/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/24 10:34:55 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	swap_init(t_swap *swap, t_node *head, t_node *node)
{
	swap->head = head;
	swap->node = node;
	swap->ptr = head;
	swap->prev = NULL;
}

static t_node	*node_connect(t_node *head, t_node *node,
	t_cont *cont, struct stat *st)
{
	t_swap	swap[1];

	swap_init(swap, head, node);
	if (!swap->node)
		node_collect_util(swap->ptr, st, cont);
	else
	{
		node_collect_util(swap->node, st, cont);
		while (swap->ptr)
		{
			if (cont->opt->tim)
			{
				if (date_sort(swap, cont))
					return (swap->head);
			}
			else
				if (lexi_sort(swap, cont))
					return (swap->head);
			swap->prev = swap->ptr;
			swap->ptr = swap->ptr->next;
		}
		if (!swap->ptr)
			swap->prev->next = swap->node;
	}
	return (swap->head);
}

static t_node	*lstat_fail(char *path, struct stat *st,
	t_node *head, t_node *node)
{
	free(path);
	free(st);
	if (!node)
	{
		free(head);
		head = NULL;
		return (head);
	}
	else
		free(node);
	return (head);
}

t_node	*node_collect(t_node *head, t_node *node, t_cont *cont)
{
	char		*path;
	struct stat	*st;

	path = get_path(cont->dir_name, cont->file_name);
	st = malloc(sizeof(struct stat));
	if (!st)
	{
		ft_printf("ft_ls: %s: Not enough memory\n", cont->file_name);
		exit(EXIT_FAILURE);
	}
	if (lstat(path, st) < 0)
	{
		ft_error(ft_strchr(path, '/') + 1, errno);
		return (lstat_fail(path, st, head, node));
	}
	free(path);
	return (node_connect(head, node, cont, st));
}

t_node	*linked_list(t_node *head, t_cont *cont)
{
	t_node	*node;

	node = NULL;
	if (!head)
	{
		head = (t_node *)malloc(sizeof(t_node));
		if (!head)
			return (NULL);
		file_node_init(head);
		head = node_collect(head, node, cont);
	}
	else
	{
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
		{
			nodes_array_delete(head, cont->opt);
			ft_printf("ft_ls: %s: Not enough memory\n", cont->file_name);
			exit(EXIT_FAILURE);
		}
		file_node_init(node);
		head = node_collect(head, node, cont);
	}
	return (head);
}
