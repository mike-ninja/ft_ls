/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/13 11:19:42 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void    nodes_array_delete(t_node *file_node)
{
    t_node  *tmp;

    while (file_node)
    {
        free(file_node->file_name);
        tmp = file_node;
        file_node = file_node->next;
        free(tmp);
    }
}

static void    file_node_collect(t_node *node, t_node *file_node, char *file_name)
{
    if (!node)
    {
        file_node->current = file_node;
        file_node->file_name = ft_strdup(file_name);
        file_node->file_type = 0;
        file_node->next = NULL;
    }
    else
    {
        file_node->next = node;
        node->current = node;
        node->file_name = ft_strdup(file_name);
        node->file_type = 0;
        node->next = NULL;
    }
}

static void    file_node_init(t_node *node)
{
   node->current = NULL;
   node->file_name = NULL;
   node->file_type = 0;
   node->next = NULL;
}

static t_node  *file_nodes_array(t_node *file_node, char *file_name)
{
    t_node  *head;
    t_node  *node;
    
    head = NULL;
    node = NULL;
    if (!file_node)
    {
        file_node = (t_node *)malloc(sizeof(t_node));
        if (!file_node)
            return (NULL);
        file_node_init(file_node);
        file_node_collect(node, file_node, file_name);
    }
    else
    {
        head = file_node;
        while (file_node->next)
            file_node = file_node->next;
        node = (t_node *)malloc(sizeof(t_node));
        if (!node)
        {
            nodes_array_delete(file_node);
            exit(1);
        }
        file_node_init(node);
        file_node_collect(node, file_node, file_name);
        return (head);
    }
    return (file_node);
}

// static void node_reader(t_node *file_node)
// {
//     while(file_node)
//     {
//         printf("%p\n", file_node->current);
//         printf("%s\n", file_node->file_name);
//         printf("%i\n", file_node->file_type);
//         printf("%p\n", file_node->next);
//         printf("\n");
//         file_node = file_node->next;
//     }
//     printf("\n");
// }

/*
    This file collects name & file type to add to a linked list.
*/
t_node  *file_name_list(const char *file_name, t_opts *opt)
{
    DIR             *dir;
    struct dirent   *dent;
    t_node          *file_node;
    
    file_node = NULL;
    dir = opendir(file_name);
    if (dir)
    {
        dent = readdir(dir);
        while (dent)
        {
            file_node = file_nodes_array(file_node, dent->d_name);
            dent = readdir(dir);
        }
        closedir(dir);
    }
    nodes_array_delete(file_node);
    return (file_node);
}
