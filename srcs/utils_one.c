/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:21:27 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/22 12:59:08 by mbarutel         ###   ########.fr       */
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
		return ('l');
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

static void	permission_parse(char *perm, int octal)
{
	int		len;
	int		perm_int;

	len = 8;
	while (len > 0)
	{
		perm_int = octal % 10;
		if (!perm_int)
		{
			perm[len] = '-';
			perm[len - 1] = '-';
			perm[len - 2] = '-';
			len -= 3;
		}
		while (perm_int)
		{
			if ((perm_int % 2) == 0)
				perm[len] = '-';
			perm_int /= 2;
			len--;
		}
		octal /= 10;
	}
}

char	*permission_str(mode_t mode)
{
	char	*octal_str;
	char	*permission;

	permission = ft_strdup("rwxrwxrwx");
	octal_str = ft_itoa_base(mode, 8);
	if (!permission || !octal_str)
		return (NULL);
	permission_parse(permission, ft_atoi(octal_str));
	free(octal_str);
	return (permission);
}
