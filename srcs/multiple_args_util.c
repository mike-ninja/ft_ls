/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:47:07 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/03 10:30:01 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	args_del(t_args *args, int index)
{
	while (index >= 0)
	{
		free(args[index].file_name);
		index--;
	}
	free(args);
}

static void	args_swap(int i, int y, t_args *args)
{
	t_args	ptr;

	ptr = args[i];
	args[i] = args[y];
	args[y] = ptr;
}

void	args_lexi_swap(int i, int y, t_args *args, t_opts *opt)
{
	if (opt->rev)
	{
		if (ft_strcmp(args[i].file_name, args[y].file_name) > 0)
			args_swap(i, y, args);
	}
	else
		if (ft_strcmp(args[i].file_name, args[y].file_name) < 0)
			args_swap(i, y, args);
}

void	args_date_swap(int i, int y, t_args *args, t_opts *opt)
{
	if (opt->rev)
	{
		if (args[i].modi_date < args[y].modi_date)
			args_swap(i, y, args);
	}
	else
		if (args[i].modi_date > args[y].modi_date)
			args_swap(i, y, args);
}

void	collect_dates(int index, t_args *args)
{
	int			i;
	struct stat	*st;

	i = -1;
	while (++i < index)
	{
		st = (struct stat *)malloc(sizeof(struct stat));
		if (lstat(args[i].file_name, st) > 0)
			args[i].modi_date = st->st_mtimespec.tv_sec;
		free(st);
	}
}
