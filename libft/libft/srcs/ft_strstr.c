/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:10:57 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/07 18:12:47 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strstr:
**	: Locates the first occurrence of the null-terminated
**   string 'needle' in the null-terminated string 'haystack'.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (((char *)needle)[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
