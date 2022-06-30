/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:17:22 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/07 17:39:36 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_lstdel:
**	: Takes as a parameter the address of a pointer to a link and frees
**   the memory of this link and every successors of that link using
**   the functions del and free(3).
** 	: The pointer to the link that was just freed is set to NULL.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	if (alst)
	{
		while (*alst)
		{
			ptr = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = ptr;
		}
		ptr = NULL;
	}
}
