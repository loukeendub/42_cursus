/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:02:33 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/16 11:48:14 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_intcount(int n)
{
	int count;

	count = 1;
	while (!(n / 10 == 0))
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = n >= 0 ? ft_intcount(n) : ft_intcount(n) + 1;
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (NULL);
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
		res[--len] = '0' + n % 10;
		n /= 10;
	}
	return (res);
}

int		unsigned_intcount(unsigned int n)
{
	unsigned int count;

	count = 1;
	while (!(n / 10 == 0))
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;
	size_t	len;

	if (n < 0)
		return (NULL);
	len = n >= 0 ? unsigned_intcount(n) : unsigned_intcount(n) + 1;
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[--len] = '0' + n % 10;
		n /= 10;
	}
	return (res);
}

char	*sign_manager(char *s, char *t)
{
	if (g_c->sign == 0)
	{
		if (g_c->flags[2] == ' ')
			s = ft_strjoin(" ", s);
		else if (g_c->flags[2] == '+')
			s = ft_strjoin("+", s);
	}
	else
		s = ft_strjoin("-", s);
	return (s);
}
