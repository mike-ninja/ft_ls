/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 15:02:30 by mbarutel         ###   ########.fr       */
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

t_node	*ft_ls(const char *file_name, t_cont *cont)
{
	DIR				*dir;
	t_node			*node;
	struct dirent	*dent;

	node = NULL;
	dent = NULL;
	cont->blocks = 0;
	dir = opendir(file_name);
	if (dir)
	{
		dent = opt_all(dir, dent, cont->opt);
		while (dent)
		{	
			cont->file_name = dent->d_name;
			cont->dir_name = (char *)file_name;
			node = linked_list(node, cont);
			dent = readdir(dir);
		}
		closedir(dir);
		print(node, cont->opt, &cont->blocks, (char *)file_name, cont);
		nodes_array_delete(node);
	}
	else
		ft_printf("ft_ls: %s: No such file or directory\n", file_name);
	return (node);
}

static void	cont_init(t_cont *placehold)
{
	placehold->file_name = NULL;
	placehold->dir_name = NULL;
	placehold->opt = NULL;
}

int	main(int ac, char **av)
{
	int		index;
	t_opts	opts[1];
	t_cont	container[1];

	index = 1;
	init_struct(opts);
	cont_init(container);
	while (index < ac && *av[index] == '-')
	{
		options_parse(opts, av[index]);
		index++;
	}
	container->opt = opts;
	if (index == ac)
		ft_ls(".", container);
	while (index < ac)
	{
		ft_ls(av[index], container);
		index++;
	}
	return (0);
}
