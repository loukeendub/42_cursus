/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:17:41 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/12 14:17:56 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hex_conv(unsigned int n)
{
	size_t	len;
	char	*res;
	char	*hex;

	if (g_carrier->type == 'X')
		hex = "0123456789ABCDEF";
	else if (g_carrier->type == 'x')
		hex = "0123456789abcdef";
	len = ft_intcount(n);
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (0);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[--len] = hex[(n % 16)];
		n /= 16;
	}
	return (res);
	return (res);
}

char	*ptr_conv(unsigned long long n)
{
	size_t	len;
	char	*res;
	char	*hex;

	hex = "0123456789abcdef";
	len = ft_intcount(n);
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (0);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[--len] = hex[(n % 16)];
		n /= 16;
	}
	return (res);
	return (res);
}
