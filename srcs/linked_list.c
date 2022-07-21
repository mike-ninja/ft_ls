/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 15:24:00 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static bool	lexi_insertion(t_node **head, t_node *node, t_node *file_node, t_node *prev, t_opts *opt)
{
	if (opt->rev)
	{
		if ((strcmp(node->file_name, file_node->file_name)) > 0)
		{
			node->next = file_node;
			if (prev)
				prev->next = node;
			else
				*head = node;
			return (true);
		}
		return (false);
	}
	if ((strcmp(node->file_name, file_node->file_name)) < 0)
	{
		node->next = file_node;
		if (prev)
			prev->next = node;
		else
			*head = node;
		return (true);
	}
	return (false);
}

static bool date_insertion(t_node **head, t_node *node, t_node *file_node, t_node *prev, t_opts *opt)
{
	if (opt->rev)
	{
		if (node->s_date.tv_sec < file_node->s_date.tv_sec)
		{
			node->next = file_node;
			if (prev)
				prev->next = node;
			else
				*head = node;
			return (true);
		}
		if (node->s_date.tv_sec == file_node->s_date.tv_sec)
		{
			if ((strcmp(node->file_name, file_node->file_name)) > 0)
			{
				node->next = file_node;
				if (prev)
					prev->next = node;
				else
					*head = node;
				return (true);
			}
		}
		return (false);
	}
	if (node->s_date.tv_sec > file_node->s_date.tv_sec)
	{
		node->next = file_node;
		if (prev)
			prev->next = node;
		else
			*head = node;
		return (true);
	}
	if (node->s_date.tv_sec == file_node->s_date.tv_sec)
	{
		if ((strcmp(node->file_name, file_node->file_name)) < 0)
		{
			node->next = file_node;
			if (prev)
				prev->next = node;
			else
				*head = node;
			return (true);
		}
	}
	return (false);
}

t_node	*file_node_collect(t_node *node, t_node *file_node, t_cont *cont)
{
	char		*path;
	struct stat	*stat;
	t_node		*prev;
	t_node 		*head;

	prev = NULL;
	head = file_node;
	path = get_path(cont->dir_name, cont->file_name);
	stat = malloc(sizeof(struct stat));
	if (!stat)
		exit(3);
	lstat(path, stat);
	free(path);
	if (!node)
		node_collect_util(file_node, stat, &cont->blocks, cont->file_name);
	else
	{
		node_collect_util(node, stat, &cont->blocks, cont->file_name);
		while(file_node)
		{
			if (!cont->opt->tim)
			{	
				if (lexi_insertion(&head, node, file_node, prev, cont->opt))
					return (head);
			}
			else
			{
				if (date_insertion(&head, node, file_node, prev, cont->opt))
					return (head);
			}
			prev = file_node;
			file_node = file_node->next;
		}
		if (!file_node)
			prev->next = node;
	}
	return (head);
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
