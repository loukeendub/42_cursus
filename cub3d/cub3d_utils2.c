/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:27:00 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/31 12:52:34 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!dst)
		return (0);
	while (src[len])
		len++;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

size_t	ft_strcount(char *str, char c)
{
	size_t	countstr;

	countstr = 0;
	while (*str)
	{
		if (*str != c)
			if (*(str + 1) == c || *(str + 1) == '\0')
				countstr++;
		str++;
	}
	return (countstr);
}

size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 1;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		else
			i++;
	}
	return (i);
}

int	ft_split_core(char *s, char **arr, char c, t_all *all)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		if (s[i] != c)
		{
			len = ft_strclen(s, c);
			arr[i] = malloc(len + 1);
			if (!arr[i])
				return (0);
			ft_strlcpy(arr[i], s, len + 1);
			s += len;
			i++;
			all->par->map_h++;
		}
		else
			i++;
	}
	return (i); 
}

char	**ft_split(char *s, char c, t_all *all)
{
	int		i;
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(s) * (ft_strcount(s, c) + 1));
	if (!arr)
		return (NULL);
	i = ft_split_core(s, arr, c, all);
	arr[i] = NULL;
	return (arr);
}

