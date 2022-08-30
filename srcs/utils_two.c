/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:59:24 by mbarutel          #+#    #+#             */
/*   Updated: 2022/08/30 14:08:46 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*get_owner_name(uid_t uid)
{
	struct passwd	*user_info;

	user_info = getpwuid(uid);
	if (!user_info)
		return (ft_itoa(uid));
	return (ft_strdup(user_info->pw_name));
}

char	*get_owner_group(gid_t gid)
{
	struct group	*user_group;

	user_group = getgrgid(gid);
	return (user_group->gr_name);
}

static int	len_year(char *date)
{
	int len;
	int ret;

	len = ft_strlen(date) - 1;
	ret = len;
	len--;
	while (date[len] < '0' || date[len] > '9')
		len--;
	while (len)
	{
		if (date[len] < '0' || date[len] > '9')
			break;
		len--;
	}
	return (ret - len);
}

static char	*date_format(time_t epoch_sec)
{
	char	*date;
	time_t	curr_time;
	int		len;

	len = 0;
	date = NULL;
	curr_time = time(0);
	if ((curr_time - epoch_sec) > SIX_MONTHS || epoch_sec > curr_time)
	{
		len = len_year(ctime(&epoch_sec));
		// ft_printf("len %d\n", len);
		date = (char *)malloc(len - 1);
		if (!date)
			return (NULL);
		date[len - 2] = '\0';
		ft_strncpy(date, &ctime(&epoch_sec)[ft_strlen(ctime(&epoch_sec)) - len], len - 1);
	}
	else
	{
		date = (char *)malloc(6);
		if (!date)
			return (NULL);
		date[5] = '\0';
		ft_strncpy(date, &ctime(&epoch_sec)[11], 5);
	}
	return (date);
}

char	**last_modification_date(struct timespec mtimespec)
{
	char	**date;

	date = NULL;
	date = (char **)malloc(sizeof(char *) * 2);
	if (!date)
		return (NULL);
	date[0] = (char *)malloc(7);
	if (!date[0])
		return (NULL);
	date[0][6] = '\0';
	ft_strncpy(*date, &ctime(&mtimespec.tv_sec)[4], 6);
	/**********/
	// ft_printf("[%s]\n", ctime(&mtimespec.tv_sec));
	/**********/
	date[1] = date_format(mtimespec.tv_sec);
	return (date);
}

char	*permission_bits(mode_t mode)
{
	char	*ret;

	ret = ft_strdup("rwxrwxrwx");
	if (mode & S_ISUID)
	{
		if (mode & S_IXUSR)
			ret[2] = 's';
		else
			ret[2] = 'S';
	}
	if (mode & S_ISGID)
	{
		if (mode & S_IXGRP)
			ret[5] = 's';
		else
			ret[5] = 'l';
	}
	if (mode & S_ISVTX)
	{
		if (mode & S_IXOTH)
			ret[8] = 't';
		else
			ret[8] = 'T';
	}
	return (ret);
}
