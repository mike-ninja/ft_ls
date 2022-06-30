/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:04:29 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:04:29 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_memccpy:
**	: The memccpy() function copies bytes from string src to string dst.
**	: If the character c (as converted to an unsigned char) occurs in the
**   string src, the copy stops and a pointer to the byte after the copy of
**   c in the string dst is returned. Otherwise, n bytes are copied, and a
**   NULL pointer is returned.
*/

void	*
	ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (&((unsigned char *)dst)[i + 1]);
		i++;
	}
	return (NULL);
}
