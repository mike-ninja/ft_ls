/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:11:06 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/09 09:33:31 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strsub:
**	: Allocates (with malloc(3)) and returns a “fresh” substring from the
**   string given as argument.
**	: The substring begins at indexstart and is of size len.
**	: If start and len aren’t refer- ing to a valid substring, the behavior
**   is undefined.
**	: If the allocation fails, the function returns NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s && *s)
	{
		ret = (char *)malloc(sizeof(char) * (len + 1));
		if (ret)
		{
			i = 0;
			while (i < len && start <= ft_strlen(s))
			{
				ret[i] = s[start];
				i++;
				start++;
			}
			ret[i] = '\0';
			return (ret);
		}
	}
	return (NULL);
}
