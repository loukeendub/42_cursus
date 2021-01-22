/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:30:49 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/20 16:42:54 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		res[0] = '-';
	}
	while (n > 0)
	{
		res[--len] = '0' + n % 10;
		n /= 10;
	}
	return (res);
}
