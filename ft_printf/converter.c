/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:02:33 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/03 13:59:46 by lmarzano         ###   ########.fr       */
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
