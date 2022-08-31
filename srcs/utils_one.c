/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:21:27 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/31 12:18:01 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	attr_struct_init(t_col *attr)
{
	attr->norm_col = 0;
	attr->norm_row = 0;
	attr->links_len = 0;
	attr->owner_name_len = 0;
	attr->owner_group_len = 0;
	attr->name_len = 0;
	attr->file_size_len = 0;
	attr->major_len = 0;
	attr->minor_len = 0;
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
	return ('?');
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

static void	permission_parse(char *tmp, char *permission, int index)
{
	int		pow_of;
	int		index_1;
	int		perm_val;

	pow_of = 4;
	index_1 = 0;
	perm_val = *tmp - '0';
	while (index_1 < 3)
	{
		if (perm_val / pow_of != 0)
			perm_val -= pow_of;
		else
			permission[index + index_1] = '-';
		pow_of -= pow_of / 2;
		index_1++;
	}
}

char	*permission_str(mode_t mode)
{
	int		index;
	char	*permission;
	char	*octal_str;
	char	*tmp;

	index = 0;
	tmp = NULL;
	permission = ft_strdup("rwxrwxrwx");
	octal_str = ft_itoa_base(mode, 8);
	if (!permission || !octal_str)
		return (NULL);
	tmp = ft_strdup(&octal_str[ft_strlen(octal_str) - 3]);
	while (index < 9)
	{
		permission_parse(tmp, permission, index);
		tmp++;
		index += 3;
	}
	permission_bits(mode, permission);
	free(tmp - 3);
	free(octal_str);
	return (permission);
}
