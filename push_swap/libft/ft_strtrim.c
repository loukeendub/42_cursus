/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:56:57 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/17 14:20:33 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinset(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_isinset(set, s1[start]) && s1[start])
		start++;
	while (end > start && ft_isinset(set, s1[end - 1]))
		end--;
	s2 = malloc(end - start + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + start, end - start + 1);
	return (s2);
}
