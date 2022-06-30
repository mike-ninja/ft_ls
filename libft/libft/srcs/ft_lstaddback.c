/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:17:07 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:32:41 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_lstaddback:
**	: Adds the element 'new' at the back of the list.
*/

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*link;

	if (*alst)
	{
		link = *alst;
		while (link->next)
			link = link->next;
		link->next = new;
	}
	else
		*alst = new;
}
