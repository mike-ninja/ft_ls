/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:09:01 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/09 10:02:42 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strlcat:
**	: Appends string src to the end of dst.
**	: It will append at most dstsize - strlen(dst) - 1 characters.
**	: It will then NUL-terminate, unless dstsize is 0 or the original dst 
**   string was longer than dstsize (in practice this should not happen as
**   it means that either dstsize is incorrect or that dst is not a proper
**   string).
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst < dstsize)
		res = len_dst + len_src;
	else
		res = len_src + dstsize;
	while (src[i] != '\0' && (len_dst + 1) < dstsize)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (res);
}
