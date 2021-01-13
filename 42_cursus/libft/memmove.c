/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:56:10 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/13 13:22:58 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*ptrs;
	char			*ptrd;
	char			tmp[len];
	unsigned int	i;

	ptrd = (char *)dst;
	ptrs = (char *)src;
	i = 0;
	while (i < len)
	{
		tmp[i] = ptrs[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		ptrd[i] = tmp[i];
		i++;
	}
	return (dst);
}
