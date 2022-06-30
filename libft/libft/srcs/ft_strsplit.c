/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:00:29 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/13 14:08:11 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strsplit:
**	: Allocates (with malloc(3)) and returns an array of “fresh” strings
**   (all ending with ’\0’, including the array itself), obtained by
**   spliting s using the character c as a delimiter.
**	: If the allocation fails the function returns NULL.
*/

static char	*word_array(const char *str, char c)
{
	int		i;
	char	*ret;

	if (str)
	{
		i = 0;
		while (str[i] != c && str[i] != '\0')
			i++;
		ret = (char *)malloc(sizeof(char) * (i + 1));
		if (ret)
		{
			i = 0;
			while (str[i] != c && str[i] != '\0')
			{
				ret[i] = str[i];
				i++;
			}
			ret[i] = '\0';
			return (ret);
		}
	}
	return (NULL);
}

static int	word_count(const char *str, char c)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			if (str[index] != c && (str[index + 1] == c
					||str[index + 1] == '\0'))
				words++;
			index++;
		}
	}
	return (words);
}

static char	**ft_splitter(char **ret, char const *s, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			ret[i] = word_array(s, c);
			if (!ret[i])
			{
				ft_memdel((void **)ret);
				return (NULL);
			}
		}
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**ret;

	len = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (ret && s)
	{
		ret = ft_splitter(ret, s, c, len);
		return (ret);
	}
	return (NULL);
}
