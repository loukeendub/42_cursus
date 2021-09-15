/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:47:15 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/26 16:13:00 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	while (dst[j] != 0)
		j++;
	while (src[i] != 0)
		i++;
	if (size < j)
		return (size + i);
	res = i + j;
	i = 0;
	if (size > j)
	{
		while (src[i] != 0 && j < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
	}
	dst[j] = 0;
	return (res);
}
