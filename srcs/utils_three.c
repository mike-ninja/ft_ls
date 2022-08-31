/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:19:34 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/31 12:29:45 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int	len_year(char *date)
{
	int	len;
	int	ret;

	len = ft_strlen(date) - 1;
	ret = len;
	len--;
	while (date[len] < '0' || date[len] > '9')
		len--;
	while (len)
	{
		if (date[len] < '0' || date[len] > '9')
			break ;
		len--;
	}
	return (ret - len);
}

char	*special_date_case(char *date, time_t epoch_sec)
{
	int	len;

	len = len_year(ctime(&epoch_sec));
	date = (char *)malloc(len - 1);
	if (!date)
		return (NULL);
	date[len - 2] = '\0';
	ft_strncpy(date, &ctime(&epoch_sec)
	[ft_strlen(ctime(&epoch_sec)) - len], len - 1);
	return (date);
}

void	date_print(char **date)
{
	ft_printf("%s", date[0]);
	if (!ft_strchr(date[1], ':'))
		ft_printf("  %s ", date[1]);
	else
		ft_printf(" %s ", date[1]);
}
