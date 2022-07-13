/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/13 11:21:15 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int main(int ac, char **av)
{
    int         index;
    t_opts      opts[1];

    index = 1;
    init_struct(opts);
    while (index < ac && *av[index] == '-')
    {
        options_parse(opts, av[index]);
        index++;
    }
    if (index == ac)
        file_name_list(".", opts);
    while (index < ac)
    {
        file_name_list(av[index], opts);
        index++;
    }
    return (0);
}