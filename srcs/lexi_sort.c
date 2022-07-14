/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexi_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:41:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/14 12:49:24 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    lexi_sort(t_array *array)
{
    size_t  i;
    size_t  y;
    int     ret;
    char    *tmp;

    i = 0;
    ret = 0;
    tmp = NULL;
    while (i < array->index)
    {
        y = 0;
        while (y < array->index)
        {
            ret = ft_strcmp((char *)array->name_array[i], (char *)array->name_array[y]);
            if (ret < 0)
            {
                tmp = array->name_array[i];
                array->name_array[i] = array->name_array[y];
                array->name_array[y] = tmp;
            }
            y++;
        }
        i++;
    }
}

static t_node  *array_size(t_node *file_node, t_opts *opt, size_t *index)
{
    t_node  *head;
    
    head = file_node;
    while(file_node)
    {
        if (opt->all) // implementation for 'a' flag
            index[0]++;
        file_node = file_node->next;   
        if (*file_node->file_name != '.')
            break ;
    }
    if (!opt->all)
        head = file_node;
    while (file_node)
    {
        index[0]++;   
        file_node = file_node->next;
    }
    return (head);
}

static void    array_printer(t_array *array)
{
    size_t i;

    i = 0;
    while (i < array->index)
    {
        printf("%15s", array->name_array[i]);
        i++;
    }
}

t_array *file_name_array_collect(t_node *file_node, t_opts *opt)
{
    size_t  index[1];
    char    **array;
    t_array *ret;
    
    index[0] = 0;
    ret = (t_array *)malloc(sizeof(t_array));
    if (!ret)
        return (NULL);
    file_node = array_size(file_node, opt, index);
    ret->name_array = (char **)malloc(sizeof(char *) * index[0]);
    if (!ret->name_array)
        return (NULL);
    index[0] = 0;
    while (file_node)
    {
        ret->name_array[index[0]++] = file_node->file_name;
        file_node = file_node->next;
    }
    ret->index = index[0];
    lexi_sort(ret);
    array_printer(ret);
    return (ret);
}