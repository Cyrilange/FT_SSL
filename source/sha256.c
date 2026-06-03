/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:46:46 by csalamit          #+#    #+#             */
/*   Updated: 2026/06/03 12:25:13 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ft_ssl.h"

static unsigned char	*ft_padding(const unsigned char *message, size_t original_size, size_t *new_size)
{
	uint64_t		bits_size;
	unsigned char	*padded_msg;

	*new_size = ((original_size + 9 + 63) / 64) * 64;
	padded_msg = ft_calloc(*new_size, sizeof(unsigned char));
	if (!padded_msg)
		return (NULL);
	if (message && original_size > 0)
		ft_memcpy(padded_msg, message, original_size);
	padded_msg[original_size] = 0x80;
	bits_size = (uint64_t)original_size * 8;
	int i = 0;
	while (i < 8)
	{
		padded_msg[*new_size - 8 + i] = (bits_size >> (56 - i * 8)) & 0xff;
		i++;
	}
	return (padded_msg);
}

void	ft_sha256_algo(const unsigned char *message, size_t len, unsigned char *digest) {
	uint32_t a = 0x6a09e667;
	uint32_t b = 0xbb67ae85;
	uint32_t c = 0x3c6ef372;
	uint32_t d = 0xa54ff53a;
	uint32_t e = 0x510e527f;
	uint32_t f = 0x9b05688c;
	uint32_t g = 0x1f83d9ab;
	uint32_t h = 0x5be0cd19;
}