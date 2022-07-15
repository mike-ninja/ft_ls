/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/15 15:32:05 by mbarutel         ###   ########.fr       */
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
	// printf("This happens\n");
	node->links = stat->st_nlink;
	node->owner_name = get_owner_name(stat->st_uid);
	node->owner_group = get_owner_group(stat->st_gid);
	node->size = stat->st_size;
	blocks[0] += stat->st_blocks;
	node->date = last_modification_date(stat->st_mtimespec);
	node->file_name = ft_strdup(file_name);
	node->next = NULL;
}

void	file_node_collect(const char *prefix_file_name, t_node *node, t_node *file_node, char *file_name, size_t *blocks)
{
	char		*path;
	char		*perm;
	char		*date;
	struct stat	*stat;

	

	path = get_path((char *)prefix_file_name, file_name);
	stat = malloc(sizeof(struct stat));
	if (!stat)
		exit(3);
	lstat(path, stat);
	if (!node)
	{
		node_collect_util(file_node, stat, blocks, file_name);
	}
	else
	{
		file_node->next = node;
		node_collect_util(node, stat, blocks, file_name);
	}
	
	free(stat);
	free(path);
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

t_node	*file_nodes_array(const char *prefix_file_name, t_node *file_node, char *file_name, size_t *blocks)
{
	t_node	*head;
	t_node	*node;

	head = NULL;
	node = NULL;
	if (!file_node)
	{
		file_node = (t_node *)malloc(sizeof(t_node));
		if (!file_node)
			return (NULL);
		file_node_init(file_node);
		file_node_collect(prefix_file_name, node, file_node, file_name, blocks);
	}
	else
	{
		head = file_node;
		while (file_node->next)
			file_node = file_node->next;
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
		{
			nodes_array_delete(file_node);
			exit(1);
		}
		file_node_init(node);
		file_node_collect(prefix_file_name, node, file_node, file_name, blocks);
		return (head);
	}
	return (file_node);
}
