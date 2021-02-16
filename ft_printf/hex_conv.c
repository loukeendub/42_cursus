/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:17:41 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/16 11:16:56 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hex_conv(unsigned int n)
{
	size_t	len;
	char	*res;
	char	*hex;

	hex = g_c->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	len = ft_intcount(n);
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (0);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		n *= -1;
		g_c->sign = 1;
		res[len--] = '\0';
	}
	while (n > 0)
	{
		res[--len] = hex[(n % 16)];
		n /= 16;
	}
	return (res);
}

char	*ptr_conv(size_t n)
{
	size_t	len;
	size_t	tmp;
	char	*res;
	char	*hex;

	len = 1;
	tmp = n;
	hex = "0123456789abcdef";
	while (tmp /= 16)
		len++;
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (0);
	res[len] = 0;
	while ((len--) > 0)
	{
		res[len] = hex[(unsigned int)(n % 16)];
		n /= 16;
	}
	res = ft_strjoin("0x", res);
	return (res);
}
