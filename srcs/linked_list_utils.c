/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:19:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/31 12:15:01 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	nodes_array_delete(t_node *file_node, t_opts *opt)
{
	t_node	*ptr;

	while (file_node)
	{
		free(file_node->file_name);
		if (opt->lis)
		{
			free(file_node->permission);
			free(file_node->date[0]);
			free(file_node->date[1]);
			free(file_node->date);
			if (file_node->links_to)
				free(file_node->links_to);
			free(file_node->owner_name);
		}
		ptr = file_node;
		file_node = file_node->next;
		free(ptr);
	}
}

static char	*linkage(t_cont *cont)
{
	char	linkname[256];
	char	*path;
	ssize_t	ret;

	ft_memset((void *)linkname, '\0', 255);
	path = get_path(cont->dir_name, cont->file_name);
	ret = readlink(path, linkname, 255);
	free(path);
	if (ret < 0)
	{
		ft_printf("ft_ls: %s: Readlink Error\n", cont->file_name);
		exit(EXIT_FAILURE);
	}
	return (ft_strdup(linkname));
}

void	node_collect_util(t_node *nd, struct stat *st, t_cont *cont)
{
	nd->file_name = ft_strdup(cont->file_name);
	nd->s_date = st->st_mtimespec.tv_sec;
	nd->n_date = st->st_mtimespec.tv_nsec;
	nd->file_type = file_type(st->st_mode);
	if (cont->opt->lis)
	{	
		nd->permission = permission_str(st->st_mode);
		nd->extra_attr = extra_attribute(cont->dir_name, cont->file_name);
		nd->links = st->st_nlink;
		nd->owner_name = get_owner_name(st->st_uid);
		nd->owner_group = get_owner_group(st->st_gid);
		nd->size = st->st_size;
		if (nd->file_type == 'c' || nd->file_type == 'b')
		{
			nd->major = ((int32_t)(((u_int32_t)(st->st_rdev) >> 24) & 0xff));
			nd->minor = ((int32_t)((st->st_rdev) & 0xffffff));
		}
		nd->date = last_modification_date(st->st_mtimespec);
		cont->blocks += st->st_blocks;
		if (nd->file_type == 'l')
			nd->links_to = linkage(cont);
	}
	free(st);
}

void	file_node_init(t_node *node)
{
	node->file_type = 0;
	node->permission = NULL;
	node->extra_attr = 0;
	node->links = 0;
	node->owner_name = NULL;
	node->owner_group = NULL;
	node->size = 0;
	node->major = 0;
	node->minor = 0;
	node->date = NULL;
	node->s_date = 0;
	node->n_date = 0;
	node->file_name = NULL;
	node->links_to = NULL;
	node->next = NULL;
}

bool	link_check(char *arg, t_opts *opt)
{
	struct stat	st;
	bool		ret;

	ret = false;
	if (opt->lis)
	{
		if (lstat(arg, &st) == 0)
			if (S_ISLNK(st.st_mode))
				ret = true;
	}
	return (ret);
}
