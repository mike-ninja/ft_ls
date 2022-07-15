/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:17 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/15 12:12:36 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void    nodes_array_delete(t_node *file_node)
{
    t_node  *ptr;

    while (file_node)
    {
        free(file_node->permission);
        free(file_node->date);
        free(file_node->file_name);
        ptr = file_node;
        file_node = file_node->next;
        free(ptr);
    }
}

static void    file_node_collect(const char *prefix_file_name, t_node *node, t_node *file_node, char *file_name, size_t *dir_size)
{
    char                *path;
    char                *perm;
    char                *date;
    struct stat     	*stat;

    path = get_path((char *)prefix_file_name, file_name);
    stat = malloc(sizeof(struct stat));
    lstat(path, stat);
    if (!node)
    {
        file_node->file_type = file_type(stat->st_mode);
        file_node->permission = permission_str(stat->st_mode);
        file_node->links = stat->st_nlink;
        file_node->owner_name = get_owner_name(stat->st_uid);
        file_node->owner_group = get_owner_group(stat->st_gid);
        file_node->size = stat->st_size;
        dir_size[0] += file_node->size;
        file_node->date = last_modification_date(stat->st_mtimespec);
        file_node->file_name = ft_strdup(file_name);
        file_node->next = NULL;
    }
    else
    {
        file_node->next = node;
        node->file_type = file_type(stat->st_mode);
        node->permission = permission_str(stat->st_mode);
        node->links = stat->st_nlink;
        node->owner_name = get_owner_name(stat->st_uid);
        node->owner_group = get_owner_group(stat->st_gid);
        node->size = stat->st_size;
        dir_size[0] += node->size;
        node->date = last_modification_date(stat->st_mtimespec);
        node->file_name = ft_strdup(file_name);
        node->next = NULL;
    }
    free(stat);
    free(path);
}

static void    file_node_init(t_node *node)
{
    node->file_type     = 0;
    node->permission    = NULL;
    node->links         = 0;
    node->owner_name    = NULL;
    node->owner_group   = NULL;
    node->size          = 0;
    node->date          = NULL;
    node->file_name     = NULL;
    node->next          = NULL;
}

static t_node  *file_nodes_array(const char *prefix_file_name, t_node *file_node, char *file_name, size_t *dir_size)
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
        file_node_collect(prefix_file_name, node, file_node, file_name, dir_size);
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
        file_node_collect(prefix_file_name, node, file_node, file_name, dir_size);
        return (head);
    }
    return (file_node);
}

static void node_reader(t_node *file_node, t_opts *opt, t_array *lexi_sorted, size_t *dir_size)
{
    size_t  i;
    t_node  *ptr;
    char    *perm;

    i = 0;
    perm = NULL;
    printf("Total %zu\n", dir_size[0]);
    while (i < lexi_sorted->index)
    {
        ptr = file_node;
        while (ptr)
        {
            if (ft_strcmp(lexi_sorted->name_array[i], ptr->file_name) == 0)
            {
                printf("%c", ptr->file_type);
                printf("%s", ptr->permission);
                printf("%3i", ptr->links);
                printf(" %s", ptr->owner_name);
                printf("  %s ", ptr->owner_group);
                printf(" %3i", ptr->size);
                printf(" %s ", ptr->date);
                printf("%s", ptr->file_name);
                printf("\n");
                break ;
            }
            ptr = ptr->next;
        }
        i++;
    }
}

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
    size_t          dir_size[1];
    
    file_node = NULL;
    lexi_sorted = NULL;
    dir_size[0] = 0;
    dir = opendir(file_name);
    if (dir)
    {
        dent = readdir(dir);
        while (dent)
        {
            file_node = file_nodes_array(file_name, file_node, dent->d_name, dir_size);
            dent = readdir(dir);
        }
        closedir(dir);
        lexi_sorted = file_name_array_collect(file_node, opt);
        if (opt->lis)
            node_reader(file_node, opt, lexi_sorted, dir_size); // -l flag will be implemented here
        else
            array_printer(lexi_sorted);
        if (opt->rec)
            recursive((char *)file_name, file_node, opt);
        nodes_array_delete(file_node);
        free(lexi_sorted->name_array);
        free(lexi_sorted);
    }
    return (file_node);
}
