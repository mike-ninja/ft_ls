/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:40:00 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/14 14:35:31 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    recursive(char *file_name, t_node *file_node, t_opts *opt)
{
    int     i;

    i = 0;
    while (i < 2)
    {
        file_node = file_node->next;
        i++;
    }
    while (file_node)
    {
        if (file_node->file_type == 'd')
        {
            printf("\n%s/%s\n", file_name, file_node->file_name);
            file_name_list(get_path(file_name, file_node->file_name), opt);
        }
        file_node = file_node->next;
    }
}