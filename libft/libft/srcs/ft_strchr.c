/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:07:20 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/08 22:17:30 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strchr:
**	: Locates the first occurrence of c (converted to a char) in the
**   string pointed to by s.
**	: The terminating null character is considered to be part of the
**   string; therefore if c is `\0', the functions locate the terminating `\0'.
*/

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}
