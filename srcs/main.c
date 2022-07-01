/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/01 12:47:33 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int main(int ac, char **av)
{
    int         index;
    char        buffer[255];
    s_options   opt[1];

    index = 1;
    if (ac > 1)
        ft_strcpy(buffer, av[index]);
    else
        ft_strcpy(buffer , ".");
    init_struct(opt);
    while (index < ac)
    {
        input_checker(av[index], opt);
        index++;
    }
    ft_ls(buffer);
    return (0);
}