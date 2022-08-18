/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_args_error_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:33:19 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/18 15:11:48 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

bool	first_error_check(t_args *args, int len)
{
	int		i;
	DIR		*dir;
	bool	ret;

	i = 0;
	ret = false;
	while (i < len)
	{
		dir = opendir(args[i].file_name);
		if (!dir)
		{
			if (errno == 2)
			{
				ft_printf("ft_ls: %s: %s\n", args[i].file_name, strerror(errno));
				free(args[i].file_name);
				args[i].file_name = NULL;
				ret = true;
			}
		}
		else
			closedir(dir);
		i++;
	}
	return (ret);
}

bool	second_error_check(t_args *args, int len)
{
	int		i;
	DIR		*dir;
	bool	ret;

	i = 0;
	ret = false;
	while (i < len)
	{
		dir = opendir(args[i].file_name);
		if (!dir)
		{
			if (errno == 9)
			{
				ft_printf("ft_ls: %s: %s\n", args[i].file_name, strerror(errno));
				free(args[i].file_name);
				args[i].file_name = NULL;
				ret = true;
			}
		}
		else
			closedir(dir);
		i++;
	}
	return (ret);
}

static void	dir_parse(DIR *dir, bool *new_line, t_args args, t_opts *opt)
{
	if (dir)
	{
		if (*new_line)
			ft_printf("\n");
		ft_printf("%s:\n", args.file_name);
		ft_ls(args.file_name, opt);
		closedir(dir);
		*new_line = true;
	}
	else
	{
		if (errno == 13)
		{	
			if (*new_line)
				ft_printf("\n");
			ft_printf("%s:\n", args.file_name);
			ft_error(args.file_name, errno);
			*new_line = true;
		}
	}
}

void	dir_list(int index, t_args *args, t_opts *opt, bool new_line)
{
	int		i;
	DIR		*dir;

	i = 0;
	while (i < index)
	{
		dir = opendir(args[i].file_name);
		dir_parse(dir, &new_line, args[i], opt);
		i++;
	}
}
