/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:47:07 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/08 11:02:22 by mbarutel         ###   ########.fr       */
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

static void	args_swap(t_args *args_1, t_args *args_2)
{
	uintptr_t	ptr_1;
	uintptr_t	ptr_2;

	ptr_1 = (uintptr_t)args_1->file_name;
	ptr_2 = (uintptr_t)args_2->file_name;
	ptr_1 = ptr_1 ^ ptr_2;
	ptr_2 = ptr_1 ^ ptr_2;
	ptr_1 = ptr_1 ^ ptr_2;
	args_1->file_name = (char *)ptr_1;
	args_2->file_name = (char *)ptr_2;
	args_1->modi_date = args_1->modi_date ^ args_2->modi_date;
	args_2->modi_date = args_1->modi_date ^ args_2->modi_date;
	args_1->modi_date = args_1->modi_date ^ args_2->modi_date;
}

void	args_lexi_swap(int i, int y, t_args *args, t_opts *opt)
{
	if (opt->rev && (args[i].modi_date > 0 || args[y].modi_date > 0))
	{
		if (ft_strcmp(args[i].file_name, args[y].file_name) < 0)
			args_swap(&args[i], &args[y]);
	}
	else
		if (ft_strcmp(args[i].file_name, args[y].file_name) > 0)
			args_swap(&args[i], &args[y]);
}

void	args_date_swap(int i, int y, t_args *args, t_opts *opt)
{
	if (opt->rev)
	{
		if (args[i].modi_date > args[y].modi_date)
			args_swap(&args[i], &args[y]);
	}
	else
		if (args[i].modi_date < args[y].modi_date)
			args_swap(&args[i], &args[y]);
	if (args[i].modi_date == args[y].modi_date)
		args_lexi_swap(i, y, args, opt);
}

void	collect_dates(int index, t_args *args)
{
	int			i;
	struct stat	*st;

	i = -1;
	while (++i < index)
	{
		st = (struct stat *)malloc(sizeof(struct stat));
		if (lstat(args[i].file_name, st) == 0)
			args[i].modi_date = st->st_mtimespec.tv_sec;
		free(st);
	}
}
