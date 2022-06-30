/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:04:19 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/13 22:19:45 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_memalloc:
**	: Allocates (with malloc(3)) and returns a “fresh” memory area.
**	: The memory allocated is initialized to 0.
**	: If the allocation fails, the function returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = (void *)malloc(size);
	if (ptr)
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	return (NULL);
}
