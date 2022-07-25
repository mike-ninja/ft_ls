/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:59:24 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/25 09:40:54 by mbarutel         ###   ########.fr       */
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

char	*last_modification_date(struct timespec mtimespec)
{
	char	*date;

	date = (char *)malloc(13);
	date[12] = '\0';
	ft_strncpy(date, &ctime(&mtimespec.tv_sec)[4], 12);
	return (date);
}
