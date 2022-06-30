/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:09:00 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/13 23:05:06 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_del:
**	: Supplementary function for ft_lstdel & ft_lst_delone. Frees the lst
**	content and initialising content_size to 0
*/

void	ft_del(void *content, size_t content_size)
{
	free(content);
	(void) content_size;
}
