/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 14:21:53 by mbarutel         ###   ########.fr       */
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

t_node	*ft_ls(const char *file_name, t_opts *opt)
{
	DIR				*dir;
	t_node			*node;
	struct dirent	*dent;
	size_t			blocks[1];

	node = NULL;
	dent = NULL;
	blocks[0] = 0;
	dir = opendir(file_name);
	if (dir)
	{
		dent = opt_all(dir, dent, opt);
		while (dent)
		{	
			node = file_nodes_array(file_name, node, dent->d_name, blocks, opt);
			dent = readdir(dir);
		}
		closedir(dir);
		print(node, opt, blocks, (char *)file_name);
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
	return (0); // Return Value has to be based on success of execution
}
