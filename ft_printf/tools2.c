/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:41:31 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/17 11:56:47 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	while (*(dst + i) && i < dstsize)
		++i;
	while (*src && i + 1 < dstsize)
	{
		*(dst + i) = *src;
		++src;
		++i;
	}
	if (i < dstsize)
		*(dst + i) = 0;
	while (*src++)
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s3 = malloc(len + 1)))
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, (char *)s2, len + 1);
	s3[len] = 0;
	return (s3);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size * count)))
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*fill_space(char *s)
{
	size_t	len;
	char	*tmp;

	len = g_c->wd - g_c->pr;
	if (!(tmp = ft_calloc((len + 1), sizeof(char))))
		return (0);
	len = (g_c->flags[2] == '+' || g_c->flags[2] == ' ') ? len - 1 : len;
	if (g_c->flags[1] == '#')
		len -= 2;
	tmp[len] = '\0';
	while (len-- > 0)
		tmp[len] = ' ';
	s = g_c->flags[0] == '-' ? ft_strjoin(s, tmp) : ft_strjoin(tmp, s);
	free(tmp);
	return (s);
}
