/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:05:34 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:33:44 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_putchar_fd:
**	: Outputs the char c to the file descriptor fd.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
