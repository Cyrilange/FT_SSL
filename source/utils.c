/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:27:11 by csalamit          #+#    #+#             */
/*   Updated: 2026/06/02 20:35:00 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

size_t ft_strlen(char *str) {
	size_t i = 0;
	while(str[i] != '\0') {
		i++;
	}
	return i;
}

void ft_error(char *str) {
	write(2, str , ft_strlen(str));
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t              i;
	unsigned char       *d;
	const unsigned char *s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void *ft_calloc(size_t count, size_t size)
{
	void            *ptr;
	size_t          total_size;
	size_t          i;
	unsigned char   *p;

	total_size = count * size;

	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);

	p = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

double ft_fabs(double x) {
    if (x < 0)
        return (-x);
    return (x);
}

void ft_printf_hex() {
	
}

double ft_sin(double x) {
    double term;
    double sum;
    int    i;

    term = x;
    sum = x;
    i = 1;
    while (i < 15)
    {
        term = -term * x * x / ((2 * i) * (2 * i + 1));
        sum += term;
        i++;
    }
    return (sum);
}