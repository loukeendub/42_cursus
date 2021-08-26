/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:53:11 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/18 14:49:15 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	while (haystack[h + n] && (h + n) < len)
	{
		if (needle[n] == '\0')
			return ((char *)haystack + h);
		if (haystack[n + h] != needle[n])
		{
			n = 0;
			h++;
		}
		else
			n++;
	}
	if ((!haystack[h + n] && !needle[n]) || ((h + n) == len && !needle[n]))
		return ((char *)haystack + h);
	return (NULL);
}
