/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:11:23 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:11:23 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_tolower:
**	: Converts an uppercase alphabetical character into an lowercase
**   character.
*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + (97 - 65);
	return (c);
}
