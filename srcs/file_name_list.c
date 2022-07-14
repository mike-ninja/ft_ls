/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/14 10:51:08 by mbarutel         ###   ########.fr       */
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

static void node_reader(t_node *file_node, t_opts *opt)
{
    while(file_node)
    {
        if (opt->all || *file_node->file_name != '.') // implementation for a flag
            break ;
        file_node = file_node->next;   
    }
    while(file_node)
    {        
        printf("%10s", file_node->file_name);
        file_node = file_node->next;
    }
    printf("\n");
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
            lstat(get_path((char *)file_name, dent->d_name), stat);
            file_node = file_nodes_array(file_node, dent->d_name, stat);
            free(stat);
            dent = readdir(dir);
        }
        closedir(dir);
        node_reader(file_node, opt);
        if (opt->rec)
            recursive((char *)file_name, file_node, opt);
        nodes_array_delete(file_node);
    }
    return (file_node);
}
