/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:17:54 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/09 09:33:09 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_lstmap:
**	: Iterates a list 'lst' and applies the function 'f' to each link to
**   create a “fresh” list (using malloc(3)) resulting from the successive
**   applications of f.
**	: If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;

	if (lst && f)
	{
		newlist = f(lst);
		if (!newlist)
		{
			ft_lstdel(&newlist, ft_del);
			return (NULL);
		}
		if (newlist && lst->next)
			newlist->next = ft_lstmap(lst->next, f);
		return (newlist);
	}
	return (NULL);
}
