/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:11:41 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:11:41 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_isalnum:
**	: Checks if the input integer is an alphanumeric character.
*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	if (ft_isdigit(c) == 1)
		return (1);
	return (0);
}
