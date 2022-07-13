/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexi_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:41:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/13 11:54:48 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    lexi_sort(t_node *file_node)
{
    t_node *head;
    t_node *current;

    head = file_node;
    while (file_node)
    {
        file_node = file_node->next;
    }
}