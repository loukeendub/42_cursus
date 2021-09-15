/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:50:01 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/24 10:56:36 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == 0 || needle == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		j = 0;
		i++;
	}
	return (0);
}
