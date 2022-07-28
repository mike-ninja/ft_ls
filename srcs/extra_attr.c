/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:38:34 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/28 12:16:45 by mbarutel         ###   ########.fr       */
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
