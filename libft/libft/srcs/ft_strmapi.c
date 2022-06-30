/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:09:27 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:35:28 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strmapi:
**	: Applies the function f to each character of the string passed as argument
**   by giving its index as first argument to create a “fresh” new
**   string (with malloc(3)) resulting from the successive applications of f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	if (s && f)
	{
		i = 0;
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (ptr)
		{
			while (s[i] != '\0')
			{
				ptr[i] = f(i, s[i]);
				i++;
			}
			ptr[i] = '\0';
			return (ptr);
		}
		else
			ft_strdel(&ptr);
	}
	return (NULL);
}
