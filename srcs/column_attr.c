/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:08:24 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/15 13:58:02 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	attr_struct_init(t_column *attr)
{
	attr->links_len = 0;
	attr->owner_name_len = 0;
	attr->owner_group_len = 0;
	attr->file_size_len = 0;
}

static void links_len(t_node *node, t_column *attr)
{
	int 			i;
	unsigned int	tmp;

	i = 0;
	tmp = node->links;
	while(tmp)
	{
		i++;
		tmp /= 10;
	}
	if (i > attr->links_len)
		attr->links_len = i;
}

static void owner_n_len(t_node *node, t_column *attr)
{
	int i;

	i = ft_strlen(node->owner_name);
	if (i > attr->owner_name_len)
		attr->owner_name_len = i;
}

static void owner_g_len(t_node *node, t_column *attr)
{
	int i;

	i = ft_strlen(node->owner_group);
	if (i > attr->owner_group_len)
		attr->owner_group_len = i;
}

static void file_s_len(t_node *node, t_column *attr)
{
	int 			i;
	unsigned int	tmp;

	i = 0;
	tmp = node->size;
	while(tmp)
	{
		i++;
		tmp /= 10;
	}
	if (i > attr->file_size_len)
		attr->file_size_len = i;
}

t_column	*attr_col(t_node *nodes)
{
	t_column	*ret;

	ret = NULL;
	ret = malloc(sizeof(t_column));
	if (!ret)
		return (NULL);
	attr_struct_init(ret);
	while (nodes)
	{
		links_len(nodes, ret);
		owner_n_len(nodes, ret);
		owner_g_len(nodes, ret);
		file_s_len(nodes, ret);
		nodes = nodes->next;
	}
	return (ret);
}