/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:08:24 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/24 10:41:11 by mbarutel         ###   ########.fr       */
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

static void	owner_len(t_node *node, t_col *attr, t_opts *opt)
{
	int	i;

	if (opt->lis)
	{	
		i = ft_strlen(node->owner_name);
		if (i > attr->owner_name_len)
			attr->owner_name_len = i;
		i = ft_strlen(node->owner_group);
		if (i > attr->owner_group_len)
			attr->owner_group_len = i;
	}
	i = ft_strlen(node->file_name);
	if (i > attr->name_len)
		attr->name_len = i;
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
	if ((attr->major_len + attr->minor_len) > attr->file_size_len)
		attr->file_size_len = attr->major_len + attr->minor_len;
}

static void	date_len(t_node *node, t_col *attr)
{
	int	len;

	len = ft_strlen(node->date[1]);
	if (len > attr->date_len)
		attr->date_len = len;
}

t_col	*attr_col(t_node *nodes, t_opts *opt)
{
	t_col	*ret;

	ret = malloc(sizeof(t_col));
	if (!ret)
		return (NULL);
	attr_struct_init(ret);
	while (nodes)
	{
		owner_len(nodes, ret, opt);
		if (opt->lis)
		{
			links_len(nodes, ret);
			if (nodes->file_type == 'c')
			{
				major_len(nodes, ret);
				minor_len(nodes, ret);
				len_correction(ret);
			}
			else
				file_s_len(nodes, ret);
			date_len(nodes, ret);
		}
		nodes = nodes->next;
	}
	return (ret);
}
