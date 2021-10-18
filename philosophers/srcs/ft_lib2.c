/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:16:40 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 18:17:01 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!dst)
		return (0);
	while (src[len])
		len++;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

static int	ft_intcount(long int n)
{
	int	count;

	count = 1;
	while (!(n / 10 == 0))
	{
		n /= 10;
		count++;
	}
	return (count);
}

static size_t	ft_check(long int n, size_t len)
{
	len = ft_intcount(n);
	if (n < 0)
		len += 1;
	return (len);
}

char	*ft_itoa(long int n)
{
	char	*res;
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_check(n, len);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	while (n > 0)
	{
		res[--len] = '0' + n % 10;
		n /= 10;
	}
	return (res);
}
