/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/14 12:49:41 by mbarutel         ###   ########.fr       */
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

static void    file_node_collect(const char *prefix_file_name, t_node *node, t_node *file_node, char *file_name)
{
    char *path;

    path = get_path((char *)prefix_file_name, file_name);
    file_node->stat = malloc(sizeof(struct stat));
    lstat(path, file_node->stat);
    if (!node)
    {
        file_node->file_name = ft_strdup(file_name);
        file_node->file_type = file_type(file_node->stat->st_mode);
        file_node->next = NULL;
    }
    else
    {
        file_node->next = node;
        node->file_name = ft_strdup(file_name);
        node->file_type = file_type(file_node->stat->st_mode);
        node->next = NULL;
    }
    free(file_node->stat);
    free(path);
}

static void    file_node_init(t_node *node)
{
    node->file_name  = NULL;
    node->file_type  = 0;
    node->stat       = NULL;
    node->next       = NULL;
}

static t_node  *file_nodes_array(const char *prefix_file_name, t_node *file_node, char *file_name)
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
        file_node_collect(prefix_file_name, node, file_node, file_name);
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
        file_node_collect(prefix_file_name, node, file_node, file_name);
        return (head);
    }
    return (file_node);
}

// static void node_reader(t_node *file_node, t_opts *opt, char **file_name_array)
// {
//     // while(file_node)
//     // {
//     //     if (opt->all || *file_node->file_name != '.') // implementation for a flag
//     //         break ;
//     //     file_node = file_node->next;   
//     // }
//     // while(file_node)
//     // {        
//     //     printf("%10s", file_node->file_name);
//     //     file_node = file_node->next;
//     // }
//     while (file_name_array)
//     {
//         // printf("%15s", *file_name_array);
//         file_name_array++;
//     }
//     printf("\n");
// }

/*
    This file collects name & file type to add to a linked list.
    Have array of string for printing names in lexi order
    and node will be in default order, for the sake of recursive
*/

t_node  *file_name_list(const char *file_name, t_opts *opt)
{
    DIR             *dir;
    t_array         *lexi_sorted;
    t_node          *file_node;
    struct dirent   *dent;
    
    file_node = NULL;
    lexi_sorted = NULL;
    dir = opendir(file_name);
    if (dir)
    {
        dent = readdir(dir);
        while (dent)
        {
            file_node = file_nodes_array(file_name, file_node, dent->d_name);
            dent = readdir(dir);
        }
        closedir(dir);
        lexi_sorted = file_name_array_collect(file_node, opt);
        // node_reader(file_node, opt, file_names_array);
        if (opt->rec)
            recursive((char *)file_name, file_node, opt);
        nodes_array_delete(file_node);
    }
    return (file_node);
}
