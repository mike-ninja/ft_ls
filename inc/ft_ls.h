/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:56:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/30 18:32:25 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

// Forbidden
#include <stdio.h>
#include <string.h>
// Forbidden

// Header
#include "../libft/incs/ft_printf.h"

// Directory metadata reading
#include <dirent.h>

// File metadata reading
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>

// typedef struct {
	
// 	char 	*name;
// 	char	*type;
// 	// dev_t	rdev;
// 	// mode_t	mode;
// 	// nlink_t	nlink; 
// 	// uid_t	uid;
// 	// gid_t	gid;
// 	// off_t	size;
// }				s_file;


#endif