/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:50:11 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/01 11:57:23 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	file_list(int index, char **av, int ac, t_opts *opt)
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
		dir = opendir(av[i]);
		if (!dir)
		{
			cont->dir_name = ".";
			cont->file_name = av[i];
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

static void	arr_delete(char **av, int index)
{
	while (index >= 0)
	{
		free(av[index]);
		index--;
	}
	free(av);
}

static char	**arr_dup(int ac, char **av, int index)
{
	int		i;
	char	**ret;

	ret = NULL;
	ret = (char **)malloc(sizeof(char *) * (ac - index));
	if (!ret)
		return (NULL);
	i = 0;
	while (index < ac)
	{
		ret[i] = ft_strdup(av[index]);
		if (!ret[i])
		{
			arr_delete(ret, i);
			exit(EXIT_FAILURE);
		}
		i++;
		index++;
	}
	return (ret);
}

static void	arr_sort(int ac, char **av, int i)
{
	int		index;
	int		index_1;
	char	*ptr;

	index = 0;
	while ((index + i) < ac)
	{
		index_1 = 0;
		while ((index_1 + i) < ac)
		{
			if (ft_strcmp(av[index], av[index_1]) < 0)
			{
				ptr = av[index];
				av[index] = av[index_1];
				av[index_1] = ptr;
			}
			index_1++;
		}
		index++;
	}
}

void	arg_parse(int index, int ac, char **av, t_opts *opt)
{
	char	**arr;
	int		index_del;
	int		i;
	DIR		*dir;

	index_del = index;
	arr = arr_dup(ac, av, index);
	arr_sort(ac, arr, index);
	file_list(index, arr, ac, opt);
	i = 0;
	while (index < ac)
	{
		dir = opendir(arr[i]);
		if (dir)
		{
			ft_printf("\n");
			ft_printf("%s:\n", arr[i]);
			ft_ls(arr[i], opt);
			closedir(dir);
		}
		index++;
		i++;
	}
	arr_delete(arr, (index - index_del) - 1);
}
