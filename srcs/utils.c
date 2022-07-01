/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:14:29 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/01 12:38:18 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    init_struct(s_options *opt)
{
    opt->l = 0;      
    opt->a = 0;      
    opt->r = 0;      
    opt->t = 0;      
    opt->R = 0;      
}

void    input_checker(char *av, s_options *opt)
{
    if (*av == '-')
    {
        av++;
        while(*av != '\0')
        {
            if (*av == 'l')
                opt->l = 1;
            if (*av == 'a')
                opt->a = 1;
            if (*av == 'r')
                opt->r = 1;
            if (*av == 't')
                opt->t = 1;
            if (*av == 'R')
                opt->R = 1;
            av++;
        }  
    } 
}