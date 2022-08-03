/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:50:11 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/03 14:28:47 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	file_list(int index, t_args *args, int ac, t_opts *opt)
{
	DIR		*dir;
	t_node	*node;
	t_cont	cont[1];

	node = NULL;
	cont_init(cont, opt);
	while (index++ < ac)
	{
		dir = opendir(args->file_name);
		if (!dir)
		{
			cont->dir_name = ".";
			cont->file_name = args->file_name;
			node = linked_list(node, cont);
		}
		else
			closedir(dir);
		args++;
	}
	if (node)
	{
		print(node, cont);
		ft_printf("\n");
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

static t_args	*args_dup(int index, int ac, char **av)
{
	int		i;
	int		nbr;
	t_args	*args;

	i = -1;
	nbr = index;
	args = NULL;
	args = (t_args *)malloc(sizeof(t_args) * (ac - index));
	if (!args)
	{
		ft_printf("Malloc failure\n");
		exit(EXIT_FAILURE);
	}
	while (++i < (ac - nbr))
	{
		args[i].file_name = ft_strdup(av[index]);
		if (!args[i].file_name)
			exit(EXIT_FAILURE);
		args[i].modi_date = 0;
		index++;
	}
	return (args);
}

void	arg_parse(int index, int ac, char **av, t_opts *opt)
{
	int		del;
	DIR		*dir;
	t_args	*args;

	del = index;
	args = args_dup(index, ac, av);
	args_sort((ac - index), args, opt);
	file_list(index, args, ac, opt);
	dir = opendir(args->file_name);
	while (index < ac)
	{
		if (dir)
		{
			ft_printf("%s:\n", args->file_name);
			ft_ls(args->file_name, opt);
			closedir(dir);
		}
		index++;
		args++;
		dir = opendir(args->file_name);
		if (dir)
			ft_printf("\n");
	}
	args_del(args - (index - del), (index - del) - 1);
}
