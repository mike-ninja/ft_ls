/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:36:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/06 10:05:13 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	width_print(t_flags *flags)
{
	int	ret;

	ret = 0;
	while (--flags->width > 0)
	{
		if (flags->zero)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	return (ret);
}

int	ft_char_convert(unsigned int c, t_flags *flags)
{
	int	ret;

	ret = 0;
	if (c)
	{
		if (flags->minus)
			ret += write(1, &c, 1);
		if (flags->width)
			ret += width_print(flags);
		if (!flags->minus)
			ret += write(1, &c, 1);
	}
	else
	{
		if (flags->width)
			ret += width_print(flags);
		ret += write(1, "\0", 1);
	}
	return (ret);
}
