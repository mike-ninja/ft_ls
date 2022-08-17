/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:38:34 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/17 13:52:39 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	extra_attribute(char *dir_name, char *file_name)
{
	char		ret;
	acl_t		acl;
	char		*path;
	ssize_t		xattr;
	acl_entry_t	acl_entry;

	acl = NULL;
	xattr = 0;
	path = get_path(dir_name, file_name);
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &acl_entry) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		ret = '@';
	else if (acl)
		ret = '+';
	else
		ret = ' ';
	acl_free(acl);
	free(path);
	return (ret);
}

void	file_node(t_node **node, char *f_name, t_cont *cont)
{
	if (*f_name == '/')
		cont->dir_name = "/";
	else
		cont->dir_name = ".";
	cont->file_name = f_name;
	*node = linked_list(*node, cont);
}

void	ft_error(char *arg, int err_num)
{
	ft_printf("ft_ls: ");
	if (err_num == 13)
		ft_printf(ft_strrchr(arg, '/') + 1);
	else
		ft_printf("%s", arg);
	ft_printf(": %s\n", strerror(errno));
}
