/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:35:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/18 10:29:44 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	str_width(char *str, t_flags *flags, int printed)
{
	int	ret;
	int	len;
	int	tmp;

	ret = 0;
	tmp = 0;
	if (!flags->minus)
	{
		len = (int)ft_strlen(str);
		tmp = len;
		if (flags->precision >= 0)
			if (flags->precision < len)
				tmp = flags->precision;
	}
	else
		tmp = printed;
	while ((--flags->width - tmp) >= 0)
	{
		if (flags->zero)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	return (ret);
}

int	ft_str_convert(char *str, t_flags *flags)
{
	int		ret;

	ret = 0;
	if (!str)
		str = ft_strdup("(null)");
	if (flags->minus)
		ret += ft_printer(str, flags);
	if (flags->width)
		ret += str_width(str, flags, ret);
	if (!flags->minus)
		ret += ft_printer(str, flags);
	return (ret);
}
