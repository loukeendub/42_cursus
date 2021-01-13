/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:27:29 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/13 17:33:32 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		len++;
		i++;
	}
	return (len);
}
