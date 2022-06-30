/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:18:03 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/09 10:51:02 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_lstnew:
**	: Allocates (with malloc(3)) and returns a “fresh” link.
**	: The variables content and content_size of the new link are initialized
**   by a copy of the parameters of the function.
**	: If the parameter content is null, the variable content is initialized
**   to NULL and the variable content_size is initialized to 0 even
**   if the parameter content_size isn’t.
**	: The variable next is initialized to NULL. If the allocation fails, the
**   function returns NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		if (content && content_size)
		{
			new->content = ft_memalloc(content_size);
			if (!new->content)
			{
				ft_lstdelone(&new, ft_del);
				return (NULL);
			}
			new->content = ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
