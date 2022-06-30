/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.o                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:11:13 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/07 18:12:59 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strtrim:
**	: Allocates (with malloc(3)) and returns a copy of the str given as
**   argument without whitespaces at the beginning or at the end of the str.
**	: If s has no whitespaces at the beginning or at the end, the function
**   returns a copy of s.
**	: If the allocation fails the function returns NULL.
*/

static int	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	ft_is_char(char const *s)
{
	while (*s)
	{
		if (!(ft_is_whitespace(s[0])))
			return (1);
		s++;
	}
	return (0);
}

static size_t	ft_start(char const *str)
{
	size_t	i;

	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	return (i);
}

static size_t	ft_end(char const *str)
{
	size_t	rev_i;
	size_t	end;

	rev_i = ft_strlen(str) - 1;
	end = 0;
	while (ft_is_whitespace(str[rev_i]))
		rev_i--;
	if (!(ft_is_whitespace(str[rev_i])))
		end = rev_i;
	if (end)
		return (end);
	else
		return (0);
}

char	*ft_strtrim(char const *str)
{
	size_t		len;
	char		*ret;

	if (str)
	{
		if (!(ft_is_char(str)))
		{
			ret = ft_strnew(1);
			return (ret);
		}
		else
		{
			len = ft_end(str) - ft_start(str) + 1;
			ret = ft_strnew(len);
			if (ret)
			{
				ret = ft_strsub(str, ft_start(str), len);
				return (ret);
			}
		}
	}
	return (NULL);
}
