/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:28:38 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/18 15:30:52 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_intcount_base(unsigned int n, int base)
{
	int count;

	count = 1;
	while (!(n / base == 0))
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_utoa(unsigned int n, int base)
{
	char	*res;
	size_t	len;
	char	*radix;

	radix = g_p->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	len = ft_intcount_base(n, base);
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[--len] = radix[n % base];
		n /= base;
	}
	return (res);
}

size_t	set_len(const char *format)
{
	size_t	size;

	if (g_p->wd > g_p->pr || (size_t)g_p->wd > ft_strlen(format))
	{
		size = g_p->wd;
		g_p->filler = 1; //filler prints spaces
	}
	if (g_p->wd < g_p->pr && (size_t)g_p->pr > ft_strlen(format))
	{
		size = g_p->pr;
		g_p->filler = 0; //filler prints zeroes
	}
	if (g_p->wd < g_p->pr && (size_t)g_p->pr < ft_strlen(format))
		size = ft_strlen(format);
	return (size);
}
