/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:33:04 by csalamit          #+#    #+#             */
/*   Updated: 2026/06/03 11:33:05 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/ft_ssl.h"


static void launch_md5(t_flags flag, char *str, int fd)
{
    unsigned char   digest[16];
    unsigned char   *content;
    size_t          len;
    int             i;

    (void)flag;

    if (fd >= 0) {
        content = read_fd(fd, &len);
        ft_md5_algo(content, len, digest);
        free(content);
    }
    else {
        ft_md5_algo((unsigned char *)str, ft_strlen(str), digest);
    }
    i = 0;
    while (i < 16)
    {
        ft_printf_hex(digest[i]);
        i++;
    }
    write(1, "\n", 1);
}

static int  open_file(char *filename)
{
    int fd;

    if (!filename)
    {
        ft_error("No file provided\n");
        return (-1);
    }
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_error("ft_ssl: ");
        ft_error(filename);
        ft_error(": No such file or directory\n");
        return (-1);
    }
    return (fd);
}

static void close_file(int fd)
{
    if (fd >= 0)
        close(fd);
}

static void launch_sha256(t_flags flag, char *str , int fd) {
    (void)str;
	(void)fd;
	(void)flag;
    write(1, "Executing SHA256...\n", 20);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        ft_error("usage: ft_ssl command [flags] [file/string]\n");
        return (1);
    }
    char *commands[] = {"md5", "sha256", NULL};
    int cmd_idx = -1;

    for (int i = 0; commands[i]; i++) {
        if (ft_strcmp(argv[1], commands[i]) == 0) {
            cmd_idx = i;
            break;
        }
    }
    
    if (cmd_idx == -1) {
        ft_error("ft_ssl: Error: '");
        ft_error(argv[1]);
        ft_error("' is an invalid command.\n");
        return (1);
    }

    void (*hash_functions[])(t_flags, char *, int) = {launch_md5, launch_sha256};
    t_flags flags = {0, 0, 0, 0};
    int arg_idx = 2;

    while (arg_idx < argc && argv[arg_idx][0] == '-') {
        int j = 1;
        
        while (argv[arg_idx][j]) {
            if (argv[arg_idx][j] == 'p') flags.p = 1;
            else if (argv[arg_idx][j] == 'q') flags.q = 1;
            else if (argv[arg_idx][j] == 'r') flags.r = 1;
            else if (argv[arg_idx][j] == 's') {
                flags.s = 1;
                j++;
                break;
            } else {
                ft_error("unknown option\n");
                return (1);
            }
            j++;
        }
        arg_idx++;
    }

    if (flags.s) {
        if (arg_idx >= argc) {
            ft_error("ft_ssl: option requires an argument -- s\n");
            return (1);
        }
        hash_functions[cmd_idx](flags, argv[arg_idx], -1);
        arg_idx++;
    }

    if (arg_idx < argc) {
        while (arg_idx < argc) {
            int fd = open_file(argv[arg_idx]);
            if (fd >= 0) {
                hash_functions[cmd_idx](flags, argv[arg_idx], fd);
                close_file(fd);
            }
            arg_idx++;
        }
    } 

    else if (!flags.s) {
        hash_functions[cmd_idx](flags, NULL, 0);
    }

    return (0);
}