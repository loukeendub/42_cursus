/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:05:00 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/13 16:39:20 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*ptrs;
	char		*ptrd;

	ptrd = (char *)dst;
	ptrs = (char *)src;
	while (*ptrs && n--)
	{
		*ptrd++ = *ptrs;
		if (*ptrs == c)
			return (ptrd);
		ptrs++;
	}
	return (NULL);
}
