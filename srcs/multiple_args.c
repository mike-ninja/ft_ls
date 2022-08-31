/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:50:11 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/31 11:27:57 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static t_node	*error_check(t_cont *cont, t_args *args, t_node **node)
{
	if (args->file_name && errno != 13)
	{
		if (*args->file_name == '/')
			cont->dir_name = "/";
		else
			cont->dir_name = ".";
		cont->file_name = args->file_name;
		*node = linked_list(*node, cont);
	}
	return (*node);
}

static bool	file_list(int index, t_args *args, int ac, t_opts *opt)
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
			node = error_check(cont, args, &node);
		else
			closedir(dir);
		args++;
	}
	if (node)
	{
		node = print_nodes(node, cont);
		nodes_array_delete(node, opt);
		return (true);
	}
	return (false);
}

static void	args_sort(int index, t_args *args, t_opts *opt)
{
	int		i;
	int		y;

	i = 0;
	collect_dates(index, args);
	while (i < index)
	{
		y = i;
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
	t_args	*args;
	bool	new_line;

	args = args_dup(index, ac, av);
	args_sort((ac - index), args, opt);
	new_line = file_error_check(args, (ac - index), opt);
	new_line = file_list(index, args, ac, opt);
	dir_list((ac - index), args, opt, new_line);
	args_del(args, ((ac - index) - 1));
}
