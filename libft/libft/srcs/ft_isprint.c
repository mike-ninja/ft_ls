/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:03:55 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/19 14:03:51 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_isprint:
**	: Checks if the input integer is an ascii character that
**	 is visible on a standard output.
*/

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	return (0);
}
