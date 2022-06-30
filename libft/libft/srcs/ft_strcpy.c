/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:07:55 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:07:55 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strcpy:
**	: Copies the string src to dst (including the terminating `\0' character.)
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
