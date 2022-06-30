/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:50:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/30 11:05:50 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

// int main(int ac, char **av)
// {
//     char        *str;
//     struct stat *buff;
    
//     if (ac == 2)
//     {
//         str = NULL;
//         buff = malloc(sizeof(struct stat));
//         if (!buff)
//             return (0);
//         stat(av[1], buff);
//         // Print info of the file
//         //printf("Name: %s\n", str); This info is in readdir
//         if (buff->st_rdev == 0)
//             str = "File";
//         printf("Type: %s\n", str);
//         printf("Modes: %d\n", buff->st_mode);
//         printf("Number of links: %d\n", buff->st_nlink);
//         printf("Owner: %u\n", buff->st_uid);
//         printf("Group: %u\n", buff->st_gid);
//         printf("Size: %lld\n", buff->st_size);
//         // printf("Last modification date: %s\n", str);
//         // Printing complete
//         free(buff);
//     }
//     return (0);
// }

get_type