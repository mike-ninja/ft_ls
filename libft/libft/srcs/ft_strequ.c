/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:08:21 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/08 17:07:40 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strequ:
**	: Lexicographical comparison between s1 and s2.
**	: If the 2 strings are identical the function returns 1, or 0 otherwise.
*/

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
