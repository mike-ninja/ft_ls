/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:08:53 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/07 18:12:14 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strjoin:
**	: Allocates (with malloc(3)) and returns a “fresh” string ending 
**   with ’\0’, being the result of the concatenation of s1 and s2.
**	: If the allocation fails the function returns NULL.
*/

static void	ft_joiner(char *ret, char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*ret;

	if (s1 && s2)
	{
		len = (ft_strlen(s1) + ft_strlen(s2));
		ret = (char *)malloc(sizeof(char) * (len + 1));
		if (ret)
		{
			ft_joiner(ret, s1, s2);
			return (ret);
		}
	}
	return (NULL);
}
