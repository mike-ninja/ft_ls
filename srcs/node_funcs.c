/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 11:39:10 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	nodes_array_delete(t_node *file_node)
{
	t_node	*ptr;

	while (file_node)
	{
		free(file_node->permission);
		free(file_node->date);
		free(file_node->file_name);
		ptr = file_node;
		file_node = file_node->next;
		free(ptr);
	}
}

void	node_collect_util(t_node *node, struct stat *stat, size_t *blocks, char *file_name)
{
	node->file_type = file_type(stat->st_mode);
	node->permission = permission_str(stat->st_mode);
	node->links = stat->st_nlink;
	node->owner_name = get_owner_name(stat->st_uid);
	node->owner_group = get_owner_group(stat->st_gid);
	node->size = stat->st_size;
	blocks[0] += stat->st_blocks;
	node->date = last_modification_date(stat->st_mtimespec);
	node->s_date = stat->st_mtimespec;
	node->file_name = ft_strdup(file_name);
	node->next = NULL;
	free(stat);
}


static bool lexi_insertion(t_node **head, t_node *node, t_node *file_node, t_node *prev)
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
	return (false);
}

// static void	node_print(t_node *node)
// {
// 	t_node *ptr;

// 	ptr = node;
// 	while (ptr)
// 	{
// 		printf("%-15s\n", ptr->file_name);
// 		ptr = ptr->next;
// 	}
// }

static bool date_insertion(t_node **head, t_node *node, t_node *file_node, t_node *prev)
{
	if (node->s_date.tv_sec > file_node->s_date.tv_sec)
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

t_node	*file_node_collect(const char *prefix_file_name, t_node *node, t_node *file_node, char *file_name, size_t *blocks, t_opts *opt)
{
	char		*path;
	struct stat	*stat;
	t_node		*prev;
	t_node 		*head;

	prev = NULL;
	head = file_node;
	path = get_path((char *)prefix_file_name, file_name);
	stat = malloc(sizeof(struct stat));
	if (!stat)
		exit(3);
	lstat(path, stat);
	free(path);
	if (!node)
		node_collect_util(file_node, stat, blocks, file_name);
	else
	{
		node_collect_util(node, stat, blocks, file_name);
		while(file_node)
		{
			if (!opt->tim)
			{	
				if (lexi_insertion(&head, node, file_node, prev))
					return (head);
			}
			else
			{
				if (date_insertion(&head, node, file_node, prev))
					return (head);
			}
			prev = file_node;
			file_node = file_node->next;
		}
		if (!file_node)
			prev->next = node;
	}
	// free(stat);
	// free(path);
	return (head);
}

void	file_node_init(t_node *node)
{
	node->file_type = 0;
	node->permission = NULL;
	node->links = 0;
	node->owner_name = NULL;
	node->owner_group = NULL;
	node->size = 0;
	node->date = NULL;
	node->file_name = NULL;
	node->next = NULL;
}

t_node	*file_nodes_array(const char *prefix_file_name, t_node *file_node, char *file_name, size_t *blocks, t_opts *opt)
{
	t_node	*node;

	node = NULL;
	if (!file_node)
	{
		file_node = (t_node *)malloc(sizeof(t_node));
		if (!file_node)
			return (NULL);
		file_node_init(file_node);
		file_node = file_node_collect(prefix_file_name, node, file_node, file_name, blocks, opt);
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
		// printf("1 %p  %s\n", file_node, file_node->file_name);
		file_node = file_node_collect(prefix_file_name, node, file_node, file_name, blocks, opt);
		// printf("2 %p  %s\n", file_node, file_node->file_name);
	}
	return (file_node);
}
