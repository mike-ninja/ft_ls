/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:38:34 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/31 13:10:20 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_node	*delete_node(t_node *node, t_node **prev, t_node **head)
{
	t_node	*ret;

	ret = NULL;
	if (node->file_type != 'd')
	{	
		if (*prev)
			prev[0]->next = node->next;
		ret = node->next;
		free(node->permission);
		free(node->date[0]);
		free(node->date[1]);
		free(node->date);
		free(node->file_name);
		if (node->links_to)
			free(node->links_to);
		free(node->owner_name);
		free(node);
		return (ret);
	}
	if (!*head)
		*head = node;
	*prev = node;
	return (node->next);
}

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
	if (!*f_name)
	{
		ft_error(f_name, 2, cont->opt);
		exit(EXIT_FAILURE);
	}
	if (*f_name == '/')
		cont->dir_name = "";
	else
		cont->dir_name = ".";
	cont->file_name = f_name;
	*node = linked_list(*node, cont);
}

void	ft_error(char *arg, int err_num, t_opts *opt)
{
	char	*file_name;

	opt->exit = 1;
	file_name = NULL;
	ft_printf("ft_ls: ");
	if (err_num == 13)
	{
		file_name = ft_strrchr(arg, '/');
		if (file_name)
			ft_printf("%s", file_name + 1);
		else
			ft_printf("%s", arg);
	}
	else
		ft_printf("%s", arg);
	ft_printf(": %s\n", strerror(err_num));
}

// void	ft_error(char *arg, int err_num, t_opts *opt)
// {
// 	char	*file_name;

// 	opt->exit = 1;
// 	file_name = NULL;
// 	write(0, "ft_ls: ", 7);
// 	if (err_num == 13)
// 	{
// 		file_name = ft_strrchr(arg, '/');
// 		if (file_name)
// 			write(0, file_name + 1, ft_strlen(file_name));
// 		else
// 			write(0, arg, ft_strlen(arg));
// 	}
// 	else
// 		write(0, arg, ft_strlen(arg));
// 	write(0, ": ", 2);
// 	write(0, strerror(err_num), ft_strlen(strerror(err_num)));
// 	write(0, "\n", 1);
// }

void	line_print_nw(t_node *node)
{
	while (node)
	{
		ft_printf("%s\n", node->file_name);
		node = node->next;
	}
}
