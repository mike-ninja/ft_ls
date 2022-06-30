/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:09:36 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/14 12:31:51 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strncat:
**	: Appends not more than n characters from s2, and then adds a
**   terminating `\0'.
*/

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int		i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (j < n && src[j] != '\0')
	{
		dst[i++] = src[j];
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
