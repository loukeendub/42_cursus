/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:02:33 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/10 14:23:03 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa(int n)
{
	long	n;
	size_t	len;
	char	*res;

	n = n;
	len = (n > 0) ? 0 : 1;
	n = (n > 0) ? n : -n;
	while (n)
		n = len++ ? n / 10 : n / 10;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	*(res + len--) = '\0';
	while (n > 0)
	{
		*(res + len--) = n % 10 + '0';
		n = n / 10;
	}
	if (len == 0 && res[1] == '\0')
		*(res + len) = '0';
	if (len == 0 && res[1] != '\0')
		*(res + len) = '-';
	return (res);
}

int		ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	if (n < 0 && n > -2147483648)
		return (sign > 0 ? -1 : 0);
	n = n * sign;
	return (n);
}

void	char_conv(char *fstr)
{
	putchar(*fstr);
}

void	str_conv(char *fstr)
{}
