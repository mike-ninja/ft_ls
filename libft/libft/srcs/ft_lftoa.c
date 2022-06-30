/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 08:37:40 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/16 08:39:08 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static void	banker_round(long double nbr, char *dl_str)
{
	int	len;

	len = ft_strlen(dl_str) - 1;
	if (((long)(nbr * 10)) % 10 >= 5)
	{
		if (dl_str[len] == '9')
		{
			while (len >= 0)
			{
				if (dl_str[len] == '9')
					dl_str[len--] = '0';
				else if (dl_str[len] == '.')
					len--;
				else
				{
					dl_str[len]++;
					break ;
				}
			}
		}
		else
			dl_str[len]++;
	}
}

static char	*remainder(char *nb, long double nbr, size_t precision)
{
	char	*ret;
	char	*tmp;
	long	base;
	int		index;

	tmp = NULL;
	ret = (char *)malloc(precision + 1);
	if (!ret)
		return (NULL);
	index = 0;
	ret[precision] = '\0';
	while (precision--)
	{
		nbr *= 10;
		base = ((long)nbr) % 10;
		ret[index++] = base + '0';
	}
	tmp = ret;
	ret = ft_strjoin(nb, ret);
	free(tmp);
	free(nb);
	banker_round(nbr * 10, ret);
	return (ret);
}

static char	*joiner(char *str, size_t precision, long base)
{
	char	*tmp;

	if (!str)
		str = ft_ltoa_base(base, 10);
	else
	{
		tmp = str;
		str = ft_strjoin(str, ft_ltoa_base(base, 10));
		free(tmp);
	}
	if (precision)
	{
		tmp = str;
		str = ft_strjoin(tmp, ".");
		free(tmp);
	}
	return (str);
}

char	*ft_lftoa(long double nbr, size_t precision)
{
	char	*ret;
	long	base;

	ret = NULL;
	if (1 / nbr < 0)
	{
		ret = ft_strdup("-");
		nbr *= -1;
	}
	base = (long)nbr;
	ret = joiner(ret, precision, base);
	nbr -= (long double)base;
	ret = remainder(ret, nbr, precision);
	return (ret);
}
