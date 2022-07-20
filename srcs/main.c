/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/20 10:53:49 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	node_print(t_node *node)
{
	t_node *ptr;

	ptr = node;
	while (ptr)
	{
		printf("%-15s", ptr->file_name);
		ptr = ptr->next;
	}
	printf("\n");
}

/*
	This file collects name & file type to add to a linked list.
	Have array of string for printing names in lexi order
	and node will be in default order, for the sake of recursive
*/
t_node	*ft_ls(const char *file_name, t_opts *opt)
{
	DIR				*dir;
	t_node			*node;
	struct dirent	*dent;
	size_t			blocks[1];

	node = NULL;
	blocks[0] = 0;
	dir = opendir(file_name);
	if (dir)
	{
		dent = readdir(dir);
		if (!opt->all)
			while (*dent->d_name == '.')
				dent = readdir(dir);
		while (dent)
		{
			node = file_nodes_array(file_name, node, dent->d_name, blocks, opt);
			dent = readdir(dir);
		}
		closedir(dir);
		if (opt->lis)
			list_print(node, blocks);
		else
			node_print(node);
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
