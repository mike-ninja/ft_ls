/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:19:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 15:23:10 by mbarutel         ###   ########.fr       */
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

void	node_collect_util(t_node *nd, struct stat *st, size_t *blks, char *name)
{
	nd->file_type = file_type(st->st_mode);
	nd->permission = permission_str(st->st_mode);
	nd->links = st->st_nlink;
	nd->owner_name = get_owner_name(st->st_uid);
	nd->owner_group = get_owner_group(st->st_gid);
	nd->size = st->st_size;
	blks[0] += st->st_blocks;
	nd->date = last_modification_date(st->st_mtimespec);
	nd->s_date = st->st_mtimespec;
	nd->file_name = ft_strdup(name);
	nd->next = NULL;
	free(st);
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
