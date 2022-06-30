/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:06:59 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:34:10 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_putstr_fd:
**	: Outputs the string s to the file descriptor fd.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
