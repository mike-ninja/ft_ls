/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:21:27 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/22 11:59:36 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int	file_type(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return (3);
	if (S_ISBLK(mode))
		return (4);
	if (S_ISFIFO(mode))
		return (5);
	if (S_ISLNK(mode))
		return (6);
	if (S_ISSOCK(mode))
		return (7);
	return (0);
}

char	*get_path(char *input, char *file_name)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(input, "/");
	input = ft_strjoin(tmp, file_name);
	free(tmp);
	return (input);
}

char	*permission_str(mode_t mode)
{
	int		len;
	int		octal;
	char	*octal_str;
	int		perm_int;
	char	*permission;

	len = 8;
	permission = ft_strdup("rwxrwxrwx");
	octal_str = ft_itoa_base(mode, 8);
	if (!permission || !octal_str)
		return (NULL);
	octal = ft_atoi(octal_str);
	while (len > 0)
	{
		perm_int = octal % 10;
		while (perm_int)
		{
			if ((perm_int % 2) == 0)
				permission[len] = '-';
			perm_int /= 2;
			len--;
		}
		octal /= 10;
	}
	free(octal_str);
	return (permission);
}
