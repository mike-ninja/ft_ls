/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:56:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/01 12:47:43 by mbarutel         ###   ########.fr       */
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
#include <time.h>

typedef struct
{
    int l;
    int a;
    int r;
    int t;
    int R;
} s_options;

// Prototypes
void    ft_ls(const char *file_name);

// Utils
void    init_struct(s_options *opt);
void    input_checker(char *av, s_options *opt);

#endif