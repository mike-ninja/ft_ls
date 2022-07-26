/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:21:27 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/26 13:12:02 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	attr_struct_init(t_col *attr)
{
	attr->links_len = 0;
	attr->owner_name_len = 0;
	attr->owner_group_len = 0;
	attr->date_len = 0;
	attr->file_size_len = 0;
}

int	file_type(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
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
		ft_printf("This happens %i\n", perm_int);
		if (!perm_int)
		{
			perm[len] = '-';
			perm[len - 1] = '-';
			perm[len - 2] = '-';
			len -= 3;
		}
		while (perm_int)
		{
			ft_printf("   This happens %i\n", perm_int);
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
	ft_printf("%i\n", ft_atoi(octal_str)); // Delete this
	if (!permission || !octal_str)
		return (NULL);
	permission_parse(permission, ft_atoi(octal_str));
	free(octal_str);
	return (permission);
}
