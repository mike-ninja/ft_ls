/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:07:06 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:34:14 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_putstr:
**	: Outputs the string s to the standard output.
*/

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
