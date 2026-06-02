/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/06/02 11:20:36 by csalamit          #+#    #+#             */
/* Updated: 2026/06/02 19:45:12 by csalamit         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../include/ft_ssl.h"


static void launch_md5(char *str) {
    unsigned char digest[16];
    int           i;

    if (!str)
        return ;
    ft_md5_algo((const unsigned char *)str, ft_strlen(str), digest);
    i = 0;
	while (i < 16)
	{
		ft_printf_hex("%02x", digest[i]); // need to implemntar fn 
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

static void launch_sha256(char *str) {
    (void)str;
    write(1, "Executing SHA256...\n", 20);
}

int main(int argc, char **argv) {

    if (argc < 3) {
        ft_error("usage: ft_ssl command [flags] [file/string]\n");
        return (1);
    }

    char *commands[] = {"md5", "sha256", NULL};
   
    void (*hash_functions[])(char *str) = {launch_md5, launch_sha256};

    int i = 0;
    while (commands[i] != NULL) {
        if (ft_strcmp(argv[1], commands[i]) == 0) {
            hash_functions[i](argv[2]);
            return (0);
        }
        i++;
    }

    ft_error("ft_ssl: Error: ");
    ft_error(argv[1]);
    ft_error(" is an invalid command.\n");
    return (1);
}