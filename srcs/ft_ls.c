/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:21:27 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/30 12:30:39 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char    *file_type(mode_t mode)
{
    ft_printf("%i\n", mode);
    if (S_ISREG(mode))
        return ("File");
    if (S_ISDIR(mode))
        return ("Directory");
    if (S_ISCHR(mode))
        return ("Character Device");
    if (S_ISBLK(mode))
        return ("Block Device");
    if (S_ISFIFO(mode))
        return ("FIFO");
    if (S_ISLNK(mode))
        return ("Symbolic link");
    if (S_ISSOCK(mode))
        return ("Socket");
    return (NULL);
}

void    attr_printer(struct dirent *dent, struct stat *stat)
{
    printf("Name: %s\n", dent->d_name);
    printf("Type: %s\n", file_type(stat->st_mode));
    printf("\n");
}

char    *get_path(char *input, char *file_name)
{
    char    *tmp;
    
    tmp = NULL;
    tmp = ft_strjoin(input, "/");
    input = ft_strjoin(tmp, file_name); 
    free(tmp);
    return (input);
}

int main(int ac, char **av)
{
    DIR             *dir;
    char            buffer[50];
    struct stat     *buff;
    struct dirent   *dent;
    char            *path;
   
    if (ac > 1)
    {
        // printf("get_path %s\n", get_path(av[1]));
        strcpy(buffer, av[1]);
        dir = opendir(buffer); // This invokes dir to point to the directory named within buffer
        if (dir)
        {
            dent = readdir(dir); // readdir extracts information of the dir and puts it into dent which is a dirent struct
            while(dent) // Iterates over the directory and when it reaches the end, it will be NULL
            {
                buff = malloc(sizeof(struct stat));
                if (!buff)
                    return (0);
                // printf("get_path %s\n", get_path(av[1], dent->d_name));
                stat(get_path(av[1], dent->d_name), buff);
                attr_printer(dent, buff);
                free(buff);
                dent = readdir(dir); // Calling this function within the while loop move the dir pointer.
            }
            closedir(dir);
        }
    }
    return (0);
}

// void    init_struct(s_file  *file_attr)
// {
//     file_attr->name = NULL;
//     file_attr->type = NULL;
// }

// int main(int ac, char **av)
// {
//     // s_file          file_attr[100];
//     DIR             *dir;
//     char            buffer[50];
//     struct dirent   *dent;
   
//     if (ac > 1)
//     {
//         strcpy(buffer, av[1]);
//         dir = opendir(buffer); // This invokes dir to point to the directory named within buffer
//         if (dir)
//         {
//             dent = readdir(dir); // readdir extracts information of the dir and puts it into dent which is a dirent struct
//             while(dent) // Iterates over the directory and when it reaches the end, it will be NULL
//             {
//                 attr_printer(dent);
//                 dent = readdir(dir); // Calling this function within the while loop move the dir pointer.
//             }
//             closedir(dir);
//         }
//     }
//     return (0);
// }