/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:38:34 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/25 13:12:50 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/xattr.h>

#include "../inc/ft_ls.h"

ssize_t get_buf_len(char *file_path)
{
    ssize_t ret;

    ret = 0;
    ret = listxattr(file_path, NULL, 0, 0);
    if (ret == -1) 
    {
        perror("listxattr");
        exit(EXIT_FAILURE);
    }
    return (ret);
}

char    **extra_attr(char *file_path)
{
    ssize_t buf_len;
    // ssize_t key_len;
    // ssize_t val_len;
    char    **buf;
    // char    *key;
    // char    *val;

    buf = NULL;
    buf_len = get_buf_len(file_path);
    buf = (char **)malloc(sizeof(char *) * 2);
    buf[0] = (char *)malloc(buf_len);
    if (!buf) 
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    buf_len = listxattr(file_path, buf[0], buf_len, 0);
    if (buf_len == -1) 
    {
        perror("listxattr");
        exit(EXIT_FAILURE);
    }
    // key = buf;
    // while (buf_len > 0) 
    // {
    //     printf("key: ");
    //     printf("%s: ", key);
    //     val_len = getxattr(file_path, key, NULL, 0, 0, 0);
    //     if (val_len == -1)
    //         perror("getxattr");
    //     if (val_len > 0) 
    //     {
    //         val = malloc(val_len + 1);
    //         if (val == NULL) {
    //             perror("malloc");
    //             exit(EXIT_FAILURE);
    //         }
    //         val_len = getxattr(file_path, key, val, val_len, 0, 0);
    //         if (val_len == -1)
    //             perror("getxattr");
    //         else 
    //         {
    //             val[val_len] = 0;
    //             printf("%s", val);
    //         }
    //         free(val);
    //     } 
    //     else if (val_len == 0)
    //         printf("<no value>");
    //     printf("\n");
    //     key_len = strlen(key) + 1;
    //     buf_len -= key_len;
    //     key += key_len;
    // }
    buf[1] = ft_itoa(buf_len);
    return(buf);
}

int main(void)
{
    char **buf;

    buf = NULL;
    buf = extra_attr("/Users/mbarutel/Applications");
    printf("%s  %s\n", buf[0], buf[1]);
    if (buf)
        free(buf);
    return (0);
}