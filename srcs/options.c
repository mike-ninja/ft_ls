/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:47:13 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/27 10:55:24 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	init_struct(t_opts *opt)
{
	opt->lis = false;
	opt->all = false;
	opt->rev = false;
	opt->tim = false;
	opt->rec = false;
}

void	options_parse(t_opts *opt, char *opt_str)
{
	opt_str++;
	while (*opt_str != '\0')
	{
		if (!ft_strchr(OPTIONS, *opt_str))
		{
			ft_printf("ft_ls: illegal option -- %c\n", *opt_str);
			ft_printf("usage: ft_ls [-%s] [file ...]\n", OPTIONS);
			exit(EXIT_FAILURE);
		}
		if (*opt_str == 'l')
			opt->lis = true;
		if (*opt_str == 'a')
			opt->all = true;
		if (*opt_str == 'r')
			opt->rev = true;
		if (*opt_str == 't')
			opt->tim = true;
		if (*opt_str == 'R')
			opt->rec = true;
		opt_str++;
	}
}
