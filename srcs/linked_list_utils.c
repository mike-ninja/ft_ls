/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:19:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/25 11:05:25 by mbarutel         ###   ########.fr       */
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
		if (file_node->links_to)
			free(file_node->links_to);
		free(file_node->owner_name);
		ptr = file_node;
		file_node = file_node->next;
		free(ptr);
	}
}

static char	*linkage(t_cont *cont, struct stat *st)
{
	char	*linkname;
	char	*path;
	ssize_t	ret;

	linkname = (char *)malloc(st->st_size + 1);
	if (!linkname)
		return (NULL);
	path = get_path(cont->dir_name, cont->file_name);
	ret = readlink(path, linkname, st->st_size + 1);
	free(path);
	if (ret < 0 || ret > st->st_size)
	{
		ft_printf("ft_ls: %s: Readlink Error\n", cont->file_name);
		exit(1);
	}
	linkname[st->st_size] = '\0';
	return (linkname);
}

void	node_collect_util(t_node *nd, struct stat *st, t_cont *cont)
{
	nd->file_type = file_type(st->st_mode);
	nd->permission = permission_str(st->st_mode);
	nd->links = st->st_nlink;
	nd->owner_name = get_owner_name(st->st_uid);
	nd->owner_group = get_owner_group(st->st_gid);
	nd->size = st->st_size;
	cont->blocks += st->st_blocks;
	nd->date = last_modification_date(st->st_mtimespec);
	nd->s_date = st->st_mtimespec;
	nd->file_name = ft_strdup(cont->file_name);
	if (nd->file_type == 'l')
		nd->links_to = linkage(cont, st);
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
	node->links_to = NULL;
	node->next = NULL;
}
