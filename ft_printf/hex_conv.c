/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:17:41 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/16 17:45:01 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_hex_count(int n)
{
	int count;

	count = 1;
	while (!(n / 16 == 0))
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*hex_conv(unsigned int n)
{
	size_t	len;
	char	*res;
	char	*hex;

	hex = g_c->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	len = ft_hex_count(n);
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

char	*hex_manager(char *s)
{
	char	*t;
	size_t	l;

	s = hex_conv(va_arg(g_c->args, int));
	if (g_c->wd > 0 || g_c->pr > 0)
	{
		l = g_c->wd > g_c->pr ? g_c->wd - ft_strlen(s) : g_c->pr - ft_strlen(s);
		if (!(t = ft_calloc((l + 1), sizeof(char))))
			return (0);
		t[l] = '\0';
		s = int_precision(s, t, l);
	}
	else
	{
		l = ft_strlen(s);
		if (!(t = ft_calloc((l + 1), sizeof(char))))
			return (0);
		t[l] = '\0';
		s = int_precision(s, t, l);
	}
	return (s);
}
