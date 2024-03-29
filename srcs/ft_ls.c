/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/31 12:14:29 by mbarutel         ###   ########.fr       */
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

void	cont_init(t_cont *cont, t_opts *opt)
{
	cont->file_name = NULL;
	cont->dir_name = NULL;
	cont->blocks = 0;
	cont->opt = opt;
}

static void	read_dir(t_node **head, char *arg, DIR *dir, t_cont *cont)
{
	struct dirent	*dent;

	dent = NULL;
	if (dir && !link_check(arg, cont->opt))
	{
		cont->dir_name = arg;
		dent = readdir(dir);
		while (dent)
		{
			if (!cont->opt->all)
				dent = opt_all(dir, dent);
			if (!dent)
				break ;
			cont->file_name = dent->d_name;
			*head = linked_list(*head, cont);
			dent = readdir(dir);
		}
		if (cont->opt->lis && cont->file_name && !cont->opt->one)
			ft_printf("total %i\n", cont->blocks);
		closedir(dir);
	}
	else if (errno == 13 || errno == 9)
		ft_error(arg, errno, cont->opt);
	else
		file_node(head, arg, cont);
}

void	ft_ls(const char *arg, t_opts *opt)
{
	DIR		*dir;
	t_node	*head;
	t_cont	cont[1];

	dir = NULL;
	head = NULL;
	cont_init(cont, opt);
	dir = opendir(arg);
	read_dir(&head, (char *)arg, dir, cont);
	if (head)
	{
		head = print_nodes(head, cont);
		nodes_array_delete(head, opt);
	}
}

int	main(int ac, char **av)
{
	int		index;
	t_opts	opts[1];

	index = 1;
	opts_init(opts);
	while (index < ac && *av[index] == '-')
	{
		if (*(av[index] + 1) == '\0')
			break ;
		options_parse(opts, av[index]);
		if (ft_strcmp(av[index], "--") == 0)
		{
			index++;
			break ;
		}
		index++;
	}
	if (index == ac)
		ft_ls(".", opts);
	if (index == (ac - 1))
		ft_ls(av[index], opts);
	else
		arg_parse(index, ac, av, opts);
	exit(opts->exit);
}
