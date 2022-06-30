/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:09:45 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:09:45 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strncmp:
**	: Lexicographically compare the null-terminated strings s1 and s2 up to
**   no more than n characters.
**	: characters that appear after a `\0' character are not compared.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < (n - 1))
		i++;
	ret = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (ret);
}
