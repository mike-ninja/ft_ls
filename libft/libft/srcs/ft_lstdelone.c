/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:17:29 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/09 10:52:12 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_lstdelone:
**	: Takes as a parameter a link’s pointer address and frees the memory
**   of the link’s content using the function del given as a parameter
**	: Then frees the link’s memory using free(3). 
**	: The memory of next is not freed under any circumstance.
**	: The pointer to the link that was just freed must be set to NULL
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = NULL;
	}
}
