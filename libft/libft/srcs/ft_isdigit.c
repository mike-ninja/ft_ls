/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:03:33 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:03:33 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_isdigit:
**	: Checks if the input integer is an numeric ascii character.
*/

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}
