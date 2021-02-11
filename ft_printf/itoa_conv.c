/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:02:33 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/11 18:39:59 by lmarzano         ###   ########.fr       */
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
		res[0] = '-';
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

char	hex_conv(int n)
{
	size_t	len;
	char	*tmp;

//put conversion from int to hex here!
/*
** Divide the decimal number by 16. Treat the division as an integer division.
** Write down the remainder (in hexadecimal).
** Divide the result again by 16. Treat the division as an integer division.
** Repeat step 2 and 3 until result is 0.
** The hex value is the digit sequence of the remainders from the last to first.
*/
//use ternary operator to handle caps below
//g_carrier->type == 'X' ? "0123456789ABCDEF": "0123456789abcdefg";

	if (g_carrier->type == 'X')
		while (tmp && *tmp)
		{
			if (*tmp >= 'a' && *tmp <= 'z')
				*tmp -= 32;
			tmp++;
		}
	return (tmp);
}
