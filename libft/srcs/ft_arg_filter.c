/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:26:57 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/28 10:45:29 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	ft_address_convert(t_arg *arg, t_flags *flags)
{
	char	*hex;

	hex = ft_ulltoa_base(va_arg(arg->arg, unsigned long long), 16);
	return (ft_diouxf_printer(hex, flags, 'p'));
}

int	ft_arg_filter(t_arg *arg, t_flags *flags)
{
	int		ret;

	ret = 0;
	if (arg->specifier)
	{
		if (arg->specifier == 'c')
			ret += ft_char_convert(va_arg(arg->arg, signed int), flags);
		if (arg->specifier == 's')
			ret += ft_str_convert(va_arg(arg->arg, char *), flags);
		if (arg->specifier == 'p')
			ret += ft_address_convert(arg, flags);
		if (arg->specifier == 'b')
			ft_bin_print((size_t)va_arg(arg->arg, int), &ret);
		if (arg->specifier == 'r')
			non_printa_print(va_arg(arg->arg, int), &ret);
		if (arg->specifier == 'k')
			print_date((size_t)va_arg(arg->arg, int), &ret);
		if (arg->specifier == '%')
			ret += ft_char_convert('%', flags);
		if (ft_strchr("diouxXf", arg->specifier))
			ret += ft_diouxf_convert(arg, flags);
	}
	return (ret);
}
