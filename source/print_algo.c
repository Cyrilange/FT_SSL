/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:08:07 by csalamit          #+#    #+#             */
/*   Updated: 2026/06/04 18:00:20 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

static void	print_digest(unsigned char *d, int len)
{
	int	i = 0;

	while (i < len)
	{
		ft_printf_hex(d[i]);
		i++;
	}
}

static void	print_name_algo(char *algo, char *str, int is_file, int len)
{
	write(1, algo, ft_strlen(algo));
	write(1, " (", 2);
	if (str)
	{
		if (is_file)
			write(1, str, ft_strlen(str));
		else
			write(1, str, len);
	}
	write(1, ") = ", 4);
}

static void	print_string_only(char *str, int is_file, int len)
{
	if (!str)
		return ;

	if (is_file)
		write(1, str, ft_strlen(str));
	else
		write(1, str, len);
}

static void	print_stdin(char *str)
{

	write(1, "(", 1);
	if (str)
		write(1, str, ft_strlen(str));
	write(1, ") = ", 4);
}

void	print_flag(t_flags f, char *algo, unsigned char *d, int len, char *str, int is_file)
{
	if (f.q)
	{
		print_digest(d, len);
		write(1, "\n", 1);
		return ;
	}

	if (f.r)
	{
		print_digest(d, len);
		write(1, " ", 1);
		print_string_only(str, is_file, len);
		write(1, "\n", 1);
		return ;
	}

	if (is_file == -1)
	{
		print_stdin(str);
		print_digest(d, len);
		write(1, "\n", 1);
		return ;
	}

	print_name_algo(algo, str, is_file, len);
	print_digest(d, len);
	write(1, "\n", 1);
}