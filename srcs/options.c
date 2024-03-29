/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:47:13 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/31 11:26:22 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	opts_init(t_opts *opt)
{
	opt->lis = false;
	opt->all = false;
	opt->rev = false;
	opt->tim = false;
	opt->rec = false;
	opt->one = false;
	opt->exit = 0;
}

static void	illegal_usage(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ft_ls [-%s] [file ...]\n", OPTIONS);
	exit(EXIT_FAILURE);
}

void	options_parse(t_opts *opt, char *opt_str)
{
	opt_str++;
	if (*opt_str == '-' && opt_str[1] == '\0')
		opt_str++;
	while (*opt_str != '\0')
	{
		if (!ft_strchr(OPTIONS, *opt_str))
			illegal_usage(*opt_str);
		if (*opt_str == 'l')
		{
			opt->lis = true;
			if (opt->one)
				opt->one = false;
		}
		if (*opt_str == 'a')
			opt->all = true;
		if (*opt_str == 'r')
			opt->rev = true;
		if (*opt_str == 't')
			opt->tim = true;
		if (*opt_str == 'R')
			opt->rec = true;
		if (*opt_str == '1')
			opt->one = true;
		opt_str++;
	}
}

int	node_size(t_node *node)
{
	int	ret;

	ret = 0;
	while (node)
	{
		ret++;
		node = node->next;
	}
	return (ret);
}
