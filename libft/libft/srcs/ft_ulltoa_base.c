/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:16:54 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/08 12:32:35 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_char_val:
**	: Fetches the character value from the int
*/
static char	ft_char_val(unsigned long long val)
{
	char	ret;

	if (val >= 10)
		ret = (val - 10) + 'a';
	else
		ret = val + '0';
	return (ret);
}

/*
**	ft_deci_len:
**	: Calculates the amount of digits based on the base. Kind of like ft_strlen
*/
static int	ft_deci_len(unsigned long long val, int base)
{
	int	len;

	len = 0;
	if (val == 0)
		len++;
	while (val != 0)
	{
		len++;
		val /= base;
	}
	return (len);
}

/*
**	ft_itoa_base:
**	: Takes in a value and converts it to string based on base.
*/
char	*ft_ulltoa_base(unsigned long long value, int base)
{
	int					len;
	unsigned long long	tmp;
	char				*ret;

	tmp = value;
	len = ft_deci_len(tmp, base);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (tmp)
	{
		ret[--len] = ft_char_val(tmp % base);
		tmp /= base;
	}
	if (value == 0)
		ret[--len] = '0';
	return (ret);
}
