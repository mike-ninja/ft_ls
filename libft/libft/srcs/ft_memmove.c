/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:05:13 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:05:13 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_memmove:
**	: The memmove() function copies len bytes from string src to string dst.
**	: The two strings may overlap; the copy is always done in a non-destructive
**	 manner.
**	: Returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (i++ < len)
			((char *)dst)[len - i] = ((char *)src)[len - i];
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}	
	}
	return (dst);
}
