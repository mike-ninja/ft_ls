/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:59:24 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/26 12:09:06 by mbarutel         ###   ########.fr       */
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

static char	*date_format(time_t epoch_sec)
{
	char	*date;
	time_t	curr_time;

	date = NULL;
	curr_time = time(0);
	if ((curr_time - epoch_sec) > SIX_MONTHS)
	{
		date = (char *)malloc(5);
		if (!date)
			return (NULL);
		date[4] = '\0';
		ft_strncpy(date, &ctime(&epoch_sec)[20], 4);
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
	date[1] = date_format(mtimespec.tv_sec);
	return (date);
}
