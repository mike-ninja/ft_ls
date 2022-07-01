/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:21:27 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/01 12:07:16 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char    *file_type(mode_t mode)
{
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

char    *permission_str(mode_t mode)
{
    int     len;
    int     octal;
    char    *octal_str;
    int     perm_int;
    char    *permission;

    len = 8;
    permission = ft_strdup("rwxrwxrwx");
    octal_str = ft_itoa_base(mode, 8);
    if (!permission || !octal_str)
        return (NULL);
    octal = ft_atoi(octal_str);
    while (len > 0)
    {
        perm_int = octal % 10;
        while (perm_int)
        {
            if ((perm_int % 2) == 0)
                permission[len] = '-';
            perm_int /= 2;
            len--;
        }
        octal /= 10;
    }
    free(octal_str);
    return (permission);
}

char    *get_owner_name(uid_t uid)
{
    struct passwd *user_info;

    user_info = getpwuid(uid);
    return (user_info->pw_name);
}

char    *get_owner_group(gid_t gid)
{

    struct group *user_group;

    user_group = getgrgid(gid);
    return (user_group->gr_name);
}

char    *last_modification_date(struct timespec mtimespec)
{
    char    *date;

    date = (char *)malloc(17);
    date[16] = '\0';
    ft_strncpy(date, &ctime(&mtimespec.tv_sec)[4], 12);
    ft_strncpy(&date[12], &ctime(&mtimespec.tv_sec)[19], 5);
    return (date);
};

void    attr_printer(struct dirent *dent, struct stat *stat)
{
    char    *perm;
    char    *date;
    
    ft_printf("Name                      : %s\n", dent->d_name);
    ft_printf("Type                      : %s\n", file_type(stat->st_mode));
    perm = permission_str(stat->st_mode);
    ft_printf("Permissions               : %s\n", perm);
    ft_printf("Number of links           : %i\n", stat->st_nlink);
    ft_printf("Owner                     : %s\n", get_owner_name(stat->st_uid));
    ft_printf("Group                     : %s\n", get_owner_group(stat->st_gid));
    ft_printf("Size                      : %d\n", stat->st_size);
    date = last_modification_date(stat->st_mtimespec);
    ft_printf("Last modification date    : %s\n", date);
    free(perm);
    free(date);
    ft_printf("\n");
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

void    ft_ls(const char *file_name)
{
    DIR             *dir;
    struct stat     *buff;
    struct dirent   *dent;
    char            *path;
   
    dir = opendir(file_name);
    if (dir)
    {
        dent = readdir(dir);
        while(dent)
        {
            buff = malloc(sizeof(struct stat));
            if (!buff)
                exit(3);
            path = get_path((char *)file_name, dent->d_name);
            lstat(path, buff);
            attr_printer(dent, buff);
            free(path);
            free(buff);
            dent = readdir(dir);
        }
        closedir(dir);
    }
}
