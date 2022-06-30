/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:56:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/30 12:08:49 by mbarutel         ###   ########.fr       */
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
// Header

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef struct {
	
	char 	*name;
	char	*type;
	// dev_t	rdev;
	// mode_t	mode;
	// nlink_t	nlink; 
	// uid_t	uid;
	// gid_t	gid;
	// off_t	size;
}				s_file;


#endif