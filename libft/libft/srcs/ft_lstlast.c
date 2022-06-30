/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:44:57 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/07 14:56:38 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_lstlast:
**	: Iterates the list 'lst' up to the last link.
*/

t_list	*ft_lstlast(t_list *begin_list)
{
	if (begin_list)
	{
		while (begin_list)
			begin_list = begin_list->next;
		return (begin_list);
	}
	return (NULL);
}
