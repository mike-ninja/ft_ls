/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:08:13 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:08:13 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strdup:
**	: Allocates sufficient memory for a copy of the string s1, does the
**   copy, and returns a pointer to it.
*/

char	*ft_strdup(const char *s1)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ret)
	{
		ret = ft_strcpy(ret, s1);
		return (ret);
	}
	return (NULL);
}
