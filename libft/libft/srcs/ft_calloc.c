/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:17:08 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/07 13:22:12 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_calloc:
**	: Allocates for count objects that are size bytes of memory each and 
**	returns a pointer to the allocated memory.  The allocated memory is 
**	filled with bytes of value zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = (void *)malloc(count * size);
	if (ret)
	{
		ft_bzero(ret, (count * size));
		return (ret);
	}
	return (NULL);
}
