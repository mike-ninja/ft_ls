/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:10:25 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/13 12:08:44 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strnstr:
**	: Locates the first occurrence of the
**   null-terminated string needle in the string haystack, where not more
**   than len characters are searched.
**	: Characters that appear after a `\0' character are not searched.
*/

static size_t	confirm_match(const char *haystack,
	const char *needle, size_t limit, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	while (haystack[i] == needle[i] && limit < len)
	{
		i++;
		limit++;
		if (haystack[i] == '\0' && needle[i] == '\0')
			break ;
	}
	if (i == needle_len)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	match;

	if (needle[0] == '\0' || haystack == needle)
		return ((char *)haystack);
	index = 0;
	while (haystack[index] != '\0' && index < len)
	{
		if (haystack[index] == needle[0])
		{
			match = confirm_match(&haystack[index], needle, index, len);
			if (match == 1)
				return ((char *)&haystack[index]);
		}
		index++;
	}
	return (NULL);
}
