/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:08:24 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/26 12:12:51 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	links_len(t_node *node, t_col *attr)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	tmp = node->links;
	while (tmp)
	{
		i++;
		tmp /= 10;
	}
	if (i > attr->links_len)
		attr->links_len = i;
}

static void	owner_len(t_node *node, t_col *attr)
{
	int	i;

	i = ft_strlen(node->owner_name);
	if (i > attr->owner_name_len)
		attr->owner_name_len = i;
	i = ft_strlen(node->owner_group);
	if (i > attr->owner_group_len)
		attr->owner_group_len = i;
}

static void	file_s_len(t_node *node, t_col *attr)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	tmp = node->size;
	while (tmp)
	{
		i++;
		tmp /= 10;
	}
	if (i > attr->file_size_len)
		attr->file_size_len = i;
}

static void	date_len(t_node *node, t_col *attr)
{
	int	len;

	len = ft_strlen(node->date[1]);
	if (len > attr->date_len)
		attr->date_len = len;
}

t_col	*attr_col(t_node *nodes)
{
	t_col	*ret;

	ret = NULL;
	ret = malloc(sizeof(t_col));
	if (!ret)
		return (NULL);
	attr_struct_init(ret);
	while (nodes)
	{
		links_len(nodes, ret);
		owner_len(nodes, ret);
		file_s_len(nodes, ret);
		date_len(nodes, ret);
		nodes = nodes->next;
	}
	return (ret);
}
