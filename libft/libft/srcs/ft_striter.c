/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:08:30 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/14 12:30:54 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_striter:
**	: Applies the function f to each character of the string passed as argument.
**	: Each character is passed by address to f to be modified if necessary.
*/

void	ft_striter(char *str, void (*f)(char *))
{
	int	i;

	i = 0;
	if (str && f)
	{
		while (str[i] != '\0')
		{
			f(&str[i]);
			i++;
		}
	}
}
