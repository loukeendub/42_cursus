/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:56:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/17 14:14:32 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcount(const char *str, char c)
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

size_t	ft_strclen(const char *s, char c)
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

char	*ft_copystr(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_strclen(s, c);
			arr[i] = malloc(len + 1);
			if (!arr[i])
				return (NULL);
			ft_strlcpy(arr[i], s, len + 1);
			s += len;
			i++;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (*arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(s) * (ft_strcount(s, c) + 1));
	if (!arr)
		return (NULL);
	*arr = ft_copystr(s, c, arr);
	return (arr);
}
