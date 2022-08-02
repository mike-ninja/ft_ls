/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:50:11 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/02 15:44:17 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	file_list(int index, t_args *args, int ac, t_opts *opt)
{
	int		i;
	DIR		*dir;
	t_node	*node;
	t_cont	cont[1];

	i = -1;
	node = NULL;
	cont_init(cont, opt);
	while (++i < (ac - index))
	{
		dir = opendir(args[i].file_name);
		if (!dir)
		{
			cont->dir_name = ".";
			cont->file_name = args[i].file_name;
			node = linked_list(node, cont);
		}
		else
			closedir(dir);
	}
	if (node)
	{
		print(node, cont);
		nodes_array_delete(node);
	}
}

static void	args_sort(int index, t_args *args, t_opts *opt)
{
	int	i;
	int	y;

	i = 0;
	if (opt->tim)
		collect_dates(index, args);
	while (i < index)
	{
		y = 0;
		while (y < index)
		{
			if (opt->tim)
				args_date_swap(i, y, args, opt);
			else
				args_lexi_swap(i, y, args, opt);
			y++;
		}
		i++;
	}
}

static void	args_dup(int index, int ac, char **av, t_args *args)
{
	int	i;
	int	nbr;

	i = -1;
	nbr = index;
	while (++i < (ac - nbr))
	{
		args[i].file_name = ft_strdup(av[index]);
		if (!args[i].file_name)
			exit(EXIT_FAILURE);
		args[i].modi_date = 0;
		index++;
	}
}

void	arg_parse(int index, int ac, char **av, t_opts *opt)
{
	int		i;
	DIR		*dir;
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args) * (ac - index));
	if (!args)
		exit(EXIT_FAILURE);
	args_dup(index, ac, av, args);
	args_sort((ac - index), args, opt);
	file_list(index, args, ac, opt);
	i = 0;
	while (index < ac)
	{
		dir = opendir(args[i].file_name);
		if (dir)
		{
			ft_printf("\n");
			ft_printf("%s:\n", args[i].file_name);
			ft_ls(args[i].file_name, opt);
			closedir(dir);
		}
		index++;
		i++;
	}
	args_del(args, (i - 1));
}
