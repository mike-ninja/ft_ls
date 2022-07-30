/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/30 19:38:10 by mbarutel         ###   ########.fr       */
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

static void	cont_init(t_cont *cont, t_opts *opt)
{
	cont->file_name = NULL;
	cont->dir_name = NULL;
	cont->blocks = 0;
	cont->opt = opt;
}

static void	ft_ls_util(t_node **node, char *f_name, DIR *dir, t_cont *cont)
{
	struct dirent	*dent;

	dent = NULL;
	if (dir)
	{
		cont->dir_name = f_name;
		dent = readdir(dir);
		while (dent)
		{
			if (!cont->opt->all)
				dent = opt_all(dir, dent);
			if (!dent)
				break ;
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

t_node	*ft_ls(const char *file_name, t_opts *opt)
{
	DIR				*dir;
	t_node			*node;
	t_cont			cont[1];
	int 			index;

	node = NULL;
	dir = NULL;
	index = 1;
	cont_init(cont, opt);
	dir = opendir(file_name);
	ft_ls_util(&node, (char *)file_name, dir, cont);
	if (node)
	{
		print(node, cont);
		nodes_array_delete(node);
	}
	return (node);
}

static void file_list(int index, char **av, int ac, t_opts *opt)
{
	t_node			*node;
	t_cont			cont[1];
	DIR				*dir;

	node = NULL;
	cont_init(cont, opt);
	while(index < ac)
	{
		dir = opendir(av[index]);
		if (!dir)
		{
			cont->dir_name = ".";
			cont->file_name = av[index];
			node = linked_list(node, cont);
		}
		else
			closedir(dir);
		index++;
	}
	if (node)
	{
		print(node, cont);
		nodes_array_delete(node);
	}
}

static void	arr_delete(char **av, int index)
{
	while(index >= 0)
	{
		free(av[index]);
		index--;
	}
	free(av);
}

static char **arr_dup(int ac, char **av, int index)
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

static void print_arr(int ac, char **av, int index)
{
	int i;

	i = 0;
	while (index < ac)
	{
		ft_printf(" %s ", av[i]);
		i++;
		index++;
	}
	ft_printf("\n");
}

static void arr_sort(int ac, char **av, int i)
{
	int 	index;
	int		index_1;
	char 	*ptr;

	index = 0;
	while((index + i) < ac)
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

static void	arg_parse(int index, int ac, char **av, t_opts *opt)
{
	char	**arr;
	int		index_del;
	int		i;
	DIR		*dir;

	index_del = index;
	// ft_printf("%i\n", index);
	arr = arr_dup(ac, av, index);
	// print_arr(ac, arr, index);
	arr_sort(ac, arr, index);
	// print_arr(ac, arr, index);
	file_list(index, av, ac, opt);
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
		ft_ls(".", opts);
	if (index == (ac - 1))
		ft_ls(av[index], opts);
	else
		arg_parse(index, ac, av, opts);
	// ft_printf("%i | %i\n", index, ac);
	// while (index < ac)
	// {
	// 	ft_ls(av[index], opts, ac, av);
	// 	if (index < (ac - 1))
	// 		ft_printf("\n");
	// 	index++;
	// }
	exit(EXIT_SUCCESS);
}
