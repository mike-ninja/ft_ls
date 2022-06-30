/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:04:45 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:33:15 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_memcmp:
** 	: The memcmp() function compares byte string s1 against byte string s2.
**	: Both strings are assumed to be n bytes long.
**	: Returns zero if the two strings are identical, otherwise 1, 0, or -1 
**   depending on whether the first string is greater than, equal or lesser
**   than the second string.
**	: Treated as unsigned char values, so that `\200' is greater than `\0', 
**   for example.
**   Zero-length strings are always identical. 
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
