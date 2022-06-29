/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:21:27 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/29 12:53:20 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int main(int ac, char **av)
{
    DIR             *dir;
    struct dirent   *dent;
    char            buffer[50];

    if (ac > 1)
    {
        strcpy(buffer, av[1]);
        dir = opendir(buffer); // This invokes dir to point to the directory named within buffer
        if (dir)
        {
            dent = readdir(dir); // readdir extracts information of the dir and puts it into dent which is a dirent struct
            while(dent) // Iterates over the directory and when it reaches the end, it will be NULL
            {
                printf("%s\n", dent->d_name);
                dent = readdir(dir); // Calling this function within the while loop move the dir pointer.
            }
            closedir(dir);
        }
    }
    return (0);
}