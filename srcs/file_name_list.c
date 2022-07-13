/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/13 13:36:57 by mbarutel         ###   ########.fr       */
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

static void    file_node_collect(t_node *node, t_node *file_node, char *file_name, struct stat *stat)
{
    if (!node)
    {
        file_node->current = file_node;
        file_node->file_name = ft_strdup(file_name);
        file_node->file_type = file_type(stat->st_mode);
        file_node->next = NULL;
    }
    else
    {
        file_node->next = node;
        node->current = node;
        node->file_name = ft_strdup(file_name);
        node->file_type = file_type(stat->st_mode);
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

static t_node  *file_nodes_array(t_node *file_node, char *file_name, struct stat *stat)
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
        file_node_collect(node, file_node, file_name, stat);
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
        file_node_collect(node, file_node, file_name, stat);
        return (head);
    }
    return (file_node);
}

static void node_reader(t_node *file_node)
{
    while(file_node)
    {
        // printf("%p\n", file_node->current);
        printf("%7s", file_node->file_name);
        // printf("%i\n", file_node->file_type);
        // printf("%p\n", file_node->next);
        // printf("\n");
        file_node = file_node->next;
    }
    printf("\n");
}

static void    recursive(char *file_name, t_node *file_node, t_opts *opt)
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
        if (file_node->file_type == 2)
        {
            printf("%s/%s\n", file_name, file_node->file_name);
            file_name_list(get_path(file_name, file_node->file_name), opt);
        }
        file_node = file_node->next;
    }
}

/*
    This file collects name & file type to add to a linked list.
*/
t_node  *file_name_list(const char *file_name, t_opts *opt)
{
    DIR             *dir;
    t_node          *file_node;
    struct stat     *stat;
    struct dirent   *dent;
    
    file_node = NULL;
    dir = opendir(file_name);
    if (dir)
    {
        dent = readdir(dir);
        while (dent)
        {
            stat = malloc(sizeof(struct stat));
            if (!stat)
            {
                ft_putstr("Allocation Error: Struct Stat");
                exit(0);
            }
            lstat(get_path((char *)file_name, dent->d_name), stat); // we can change get path so ft_strjoin_
            file_node = file_nodes_array(file_node, dent->d_name, stat);
            free(stat);
            dent = readdir(dir);
        }
        closedir(dir);
        node_reader(file_node);
        recursive((char *)file_name, file_node, opt); // this causes segmentaion fault on empty dir
        nodes_array_delete(file_node);
    }
    return (file_node);
}

// t_node  *file_name_list(DIR **dir, const char *file_name, t_opts *opt)
// {
//     t_node          *file_node;
//     struct stat     *stat;
//     struct dirent   *dent;
    
//     file_node = NULL;
//     *dir = opendir(file_name);
//     printf("%s}\n", file_name);
//     if (dir)
//     {
//         printf("This happens %s}\n", file_name);
//         dent = readdir(dir);
//         while (dent)
//         {
//             stat = malloc(sizeof(struct stat));
//             if (!stat)
//             {
//                 ft_putstr("Allocation Error: Struct Stat");
//                 exit(0);
//             }
//             lstat(get_path((char *)file_name, dent->d_name), stat); // we can change get path so ft_strjoin_
//             file_node = file_nodes_array(file_node, dent->d_name, stat);
//             free(stat);
//             dent = readdir(dir);
//         }
//         closedir(dir);
//         node_reader(file_node);
//         recursive(file_node, opt); // this causes segmentaion fault on empty dir
//         nodes_array_delete(file_node);
//     }
//     return (file_node);
// }