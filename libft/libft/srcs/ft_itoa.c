/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:04:07 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/07 18:10:55 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_len:
**	: Calculates the length of the array.
*/

static int	ft_len(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

/*
**	ft_int_to_char:
** 	: The given character array is filled with converted ascii characters.
*/

static void	ft_int_to_char(char *ret, long nb, int len)
{
	ret[len] = '\0';
	if (nb == 0)
	{
		ret[0] = '0';
		return ;
	}
	if (nb < 0)
	{
		ret[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		len--;
		ret[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
}

/*
**	ft_itoa:
** 	: Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’ 
**   representing the integer n given as argument.
**   Negative numbers must be supported.
** 	: If the allocation fails, the function returns NULL.
*/

char	*ft_itoa(int nb)
{
	int		len;
	char	*ret;

	len = ft_len((long)nb);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret)
	{
		ft_int_to_char(ret, (long)nb, len);
		return (ret);
	}
	return (NULL);
}
