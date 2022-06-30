/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:31:40 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/07 14:57:31 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_lstsize:
**	: Iterates the list 'lst' to get the amount of links.
*/

int	ft_lstsize(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
