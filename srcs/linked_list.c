/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 16:32:26 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static t_node *node_connect(t_node *nd, t_node *f_nd, t_cont *cont, struct stat *stat)
{
	t_node		*head;
	t_node		*prev;

	prev = NULL;
	head = f_nd;
	if (!nd)
		node_collect_util(f_nd, stat, &cont->blocks, cont->file_name);
	else
	{
		node_collect_util(nd, stat, &cont->blocks, cont->file_name);
		while (f_nd)
		{
			if (cont->opt->tim)
			{	
				if (cont->opt->rev)
				{
					if (date_insert_rev(&head, nd, f_nd, prev))
						return (head);
				}
				else
					if (date_insert(&head, nd, f_nd, prev))
						return (head);
			}
			else
			{
				if (cont->opt->rev)
				{	
					if (lexi_insert_rev(&head, nd, f_nd, prev))
						return (head);
				}
				else
					if (lexi_insert(&head, nd, f_nd, prev))
						return (head);
			}
			prev = f_nd;
			f_nd = f_nd->next;
		}
		if (!f_nd)
			prev->next = nd;
	}
	return (head);
}

t_node	*file_node_collect(t_node *node, t_node *file_node, t_cont *cont)
{
	char		*path;
	struct stat	*stat;

	path = get_path(cont->dir_name, cont->file_name);
	stat = malloc(sizeof(struct stat));
	if (!stat)
		exit(1);
	lstat(path, stat);
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
			exit(1);
		}
		file_node_init(node);
		file_node = file_node_collect(node, file_node, cont);
	}
	return (file_node);
}
