/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_attr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:30:42 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/12 13:30:50 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	major_len(t_node *node, t_col *attr)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	tmp = node->major;
	while (tmp)
	{
		i++;
		tmp /= 10;
	}
	if (i > attr->major_len)
		attr->major_len = i;
}

void	minor_len(t_node *node, t_col *attr)
{
	int	i;
	int	tmp;

	i = 0;
	if (node->minor <= 300)
	{
		tmp = node->minor;
		while (tmp)
		{
			i++;
			tmp /= 10;
		}
		if (i > attr->minor_len)
			attr->minor_len = i;
	}
}

void	len_correction(t_col *attr)
{
	if (attr->file_size_len > (attr->major_len + attr->minor_len))
	{
		attr->major_len = attr->file_size_len >> 1;
		attr->minor_len = attr->file_size_len >> 1;
	}
}

void	rdev_print(t_node *node, t_col *col)
{
	col->file_size_len = ft_printf("%*d, ", col->major_len + 1, node->major);
	if (node->minor < 300)
		col->file_size_len += ft_printf("%*d ", col->minor_len,
				node->minor) - 1;
	else
		ft_printf("%#010x ", node->minor);
}
