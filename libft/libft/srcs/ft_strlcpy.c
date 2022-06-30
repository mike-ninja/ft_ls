/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:23:10 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/08 18:11:32 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strlcpy:
**	: Copies up to dstsize - 1 characters from the string src to
**	 dst, NUL-terminating the result if dstsize is not 0.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst && src)
	{
		if (dstsize == 0)
		{
			while (src[i] != '\0')
				i++;
			return (i);
		}
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		if (src[i] == '\0')
			return (i);
		else
			while (src[i] != '\0')
				i++;
	}
	return (i);
}
