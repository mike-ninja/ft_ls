/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:30:07 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/22 11:46:35 by mbarutel         ###   ########.fr       */
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

bool	lexi_sort(t_swap *swap, t_cont *cont)
{
	if (cont->opt->rev)
	{
		if ((strcmp(swap->node->file_name, swap->f_node->file_name)) > 0)
		{
			node_swap(&swap->head, swap->node, swap->f_node, swap->prev);
			return (true);
		}
	}
	else
	{
		if ((strcmp(swap->node->file_name, swap->f_node->file_name)) < 0)
		{
			node_swap(&swap->head, swap->node, swap->f_node, swap->prev);
			return (true);
		}
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

bool	date_sort(t_swap *swap, t_cont *cont)
{
	if (cont->opt->rev)
	{
		if (date_insert_rev(&swap->head, swap->node, swap->f_node, swap->prev))
			return (true);
	}
	else
		if (date_insert(&swap->head, swap->node, swap->f_node, swap->prev))
			return (true);
	return (false);
}
