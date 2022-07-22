/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/22 10:51:59 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static struct dirent	*opt_all(DIR *dir, struct dirent *dent, t_opts *opt)
{
	dent = readdir(dir);
	if (!opt->all)
	{
		while (dent)
		{
			if (*dent->d_name != '.')
				break ;
			dent = readdir(dir);
		}
	}
	return (dent);
}

static void	cont_init(t_cont *cont, t_opts *opt, char *file_name)
{
	cont->file_name = NULL;
	cont->dir_name = file_name;
	cont->blocks = 0;
	cont->opt = opt;
}

t_node	*ft_ls(const char *file_name, t_opts *opt)
{
	DIR				*dir;
	t_node			*node;
	struct dirent	*dent;
	t_cont			cont[1];

	node = NULL;
	dent = NULL;
	cont_init(cont, opt, (char *)file_name);
	dir = opendir(file_name);
	if (dir)
	{
		dent = opt_all(dir, dent, cont->opt);
		while (dent)
		{	
			cont->file_name = dent->d_name;
			node = linked_list(node, cont);
			dent = readdir(dir);
		}
		closedir(dir);
		print(node, cont);
		nodes_array_delete(node);
	}
	else
		ft_printf("ft_ls: %s: No such file or directory\n", file_name);
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
		options_parse(opts, av[index]);
		index++;
	}
	if (index == ac)
		ft_ls(".", opts);
	while (index < ac)
	{
		ft_ls(av[index], opts);
		index++;
	}
	return (0);
}
