/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/15 13:26:22 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
	This file collects name & file type to add to a linked list.
	Have array of string for printing names in lexi order
	and node will be in default order, for the sake of recursive
*/
t_node	*ft_ls(const char *file_name, t_opts *opt)
{
	DIR				*dir;
	t_array			*lexi_sorted;
	t_node			*file_node;
	struct dirent	*dent;
	size_t			blocks[1];

	file_node = NULL;
	lexi_sorted = NULL;
	blocks[0] = 0;
	dir = opendir(file_name);
	if (dir)
	{
		dent = readdir(dir);
		while (dent)
		{
			file_node = file_nodes_array(file_name, file_node, dent->d_name, blocks);
			dent = readdir(dir);
		}
		closedir(dir);
		lexi_sorted = file_name_array_collect(file_node, opt);
		if (opt->lis)
			list_print(file_node, opt, lexi_sorted, blocks);
		else
			standard_print(lexi_sorted);
		if (opt->rec)
			recursive((char *)file_name, file_node, opt);
		nodes_array_delete(file_node);
		free(lexi_sorted->name_array);
		free(lexi_sorted);
	}
	return (file_node);
}

int main(int ac, char **av)
{
    int         index;
    t_opts      opts[1];

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