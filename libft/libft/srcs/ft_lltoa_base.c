/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:09:23 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/16 08:43:23 by mbarutel         ###   ########.fr       */
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
	if (val < 0 && base == 10)
		len++;
	while (val != 0)
	{
		len++;
		val /= base;
	}
	return (len);
}

static void	catch_negative(int *len, long long val, int base, char *ret)
{
	if (!ret)
	{
		if (val < 0 && base == 10)
			*len = *len + 1;
	}
	else
	{
		if (val < 0 && base == 10)
			ret[0] = '-';
		if (val == 0)
			ret[0] = '0';
	}
}

/*
**	ft_itoa_base:
**	: Takes in a value and converts it to string based on base.
*/
char	*ft_lltoa_base(long long value, int base)
{
	int					len;
	unsigned long long	tmp;
	char				*ret;

	len = 0;
	ret = NULL;
	if (value < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (value < 0 && base == 10)
		tmp = value * -1;
	else
		tmp = (unsigned long long)value;
	len += ft_deci_len(tmp, base);
	catch_negative(&len, value, base, ret);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (tmp)
	{
		ret[--len] = ft_char_val(tmp % base);
		tmp /= base;
	}
	catch_negative(&len, value, base, ret);
	return (ret);
}
