/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:30:07 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 16:06:31 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	node_swap(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev)
{
	nd->next = f_nd;
	if (prev)
		prev->next = nd;
	else
		*hd = nd;
}

bool	lexi_insert(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev)
{
	if ((strcmp(nd->file_name, f_nd->file_name)) < 0)
	{
		node_swap(hd, nd, f_nd, prev);
		return (true);
	}
	return (false);
}

bool	lexi_insert_rev(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev)
{
	if ((strcmp(nd->file_name, f_nd->file_name)) > 0)
	{
		node_swap(hd, nd, f_nd, prev);
		return (true);
	}
	return (false);
}

bool	date_insert(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev)
{
	if (nd->s_date.tv_sec > f_nd->s_date.tv_sec)
	{
		node_swap(hd, nd, f_nd, prev);
		return (true);
	}
	if (nd->s_date.tv_sec == f_nd->s_date.tv_sec)
	{
		if ((strcmp(nd->file_name, f_nd->file_name)) < 0)
		{
			node_swap(hd, nd, f_nd, prev);
			return (true);
		}
	}
	return (false);
}

bool	date_insert_rev(t_node **hd, t_node *nd, t_node *f_nd, t_node *prev)
{
	if (nd->s_date.tv_sec < f_nd->s_date.tv_sec)
	{
		node_swap(hd, nd, f_nd, prev);
		return (true);
	}
	if (nd->s_date.tv_sec == f_nd->s_date.tv_sec)
	{
		if ((strcmp(nd->file_name, f_nd->file_name)) > 0)
		{
			node_swap(hd, nd, f_nd, prev);
			return (true);
		}
	}
	return (false);
}
