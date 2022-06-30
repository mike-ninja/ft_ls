/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:16:57 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/09 10:52:30 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_lstadd:
**	: Adds the element 'new' at the beginning of the list.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
}
