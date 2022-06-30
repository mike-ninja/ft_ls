/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:10:36 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/13 12:08:15 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strrchr:
**	: Locates the last occurrence of c (converted to a char) in the
**   string pointed to by s.
**	: The terminating null character is considered to be part of the
**   string; therefore if c is `\0', the functions locate the terminating `\0'.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != c && i > 0)
		i--;
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}
