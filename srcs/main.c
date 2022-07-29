/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/29 12:31:47 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static struct dirent	*opt_all(DIR *dir, struct dirent *dent)
{
	while (dent)
	{
		if (*dent->d_name != '.')
			break ;
		dent = readdir(dir);
	}
	return (dent);
}

static void	cont_init(t_cont *cont, t_opts *opt, int ac)
{
	cont->file_name = NULL;
	cont->dir_name = NULL;
	cont->blocks = 0;
	cont->opt = opt;
	cont->ac = ac;
}

static void	ft_ls_util(t_node **node, char *f_name, DIR *dir, t_cont *cont)
{
	struct dirent	*dent;

	dent = NULL;
	if (dir)
	{
		if (cont->ac > 2)
			ft_printf("%s:\n", f_name);
		cont->dir_name = f_name;
		dent = readdir(dir);
		while (dent)
		{
			if (!cont->opt->all)
				dent = opt_all(dir, dent);
			cont->file_name = dent->d_name;
			*node = linked_list(*node, cont);
			dent = readdir(dir);
		}
		closedir(dir);
		if (cont->opt->lis)
			ft_printf("total %i\n", cont->blocks);
	}
	else
	{
		cont->dir_name = ".";
		cont->file_name = f_name;
		*node = linked_list(*node, cont);
	}
}

t_node	*ft_ls(const char *file_name, t_opts *opt, int ac)
{
	DIR				*dir;
	t_node			*node;
	t_cont			cont[1];

	node = NULL;
	cont_init(cont, opt, ac);
	dir = opendir(file_name);
	ft_ls_util(&node, (char *)file_name, dir, cont);
	if (node)
	{
		print(node, cont);
		nodes_array_delete(node);
	}
	return (node);
}

int	main(int ac, char **av)
{
	int		index;
	t_opts	opts[1];

	index = 1;
	init_struct(opts);
	while (index < ac && *av[index] == '-')
	{
		if (*(av[index] + 1) == '\0')
			break ;
		options_parse(opts, av[index]);
		index++;
	}
	if (index == ac)
		ft_ls(".", opts, ac);
	while (index < ac)
	{
		ft_ls(av[index], opts, ac);
		if (index < (ac - 1))
			ft_printf("\n");
		index++;
	}
	exit(EXIT_SUCCESS);
}
