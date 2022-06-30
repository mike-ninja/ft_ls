/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:07:28 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:34:50 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strclr:
**	: Sets every character of the string to the value ’\0’.
*/

void	ft_strclr(char *s)
{
	if (s)
	{
		ft_bzero(s, ft_strlen(s));
	}
}
