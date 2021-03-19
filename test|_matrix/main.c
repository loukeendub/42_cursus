/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:36:36 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/19 14:41:28 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
	return (s3);
}

int get_next_line(int fd, char **line)
{
	int ret = 0;
	int len = 0;
	int i = 0;
	if(!line)
		return(-1);
	if (!(*line = malloc(256)))
		return(-1);
	(*line)[len] = 0;
	while ((ret = read(fd , &(*line)[i], 1)) == 1)
	{
		if ((*line)[i] == '\n')
		{
			(*line)[i] = '\n';
			(*line)[i + 1] = 0;
			return (1);
		}
		i++;
	}
	(*line)[i] = 0;
	return (ret);
}

int	main(void)
{
	char	**map;
	char	**line;
	const char	*newl;
	int		fd;
	int		i;
	int		j;
	int		rd;

	fd = open("matrix.cub", O_RDONLY);
	i = 1;
	j = 0;
	while (i)
	{
		i = get_next_line(fd, line);
		if (ft_strlen(newl) > 0)
			newl = ft_strjoin(newl, (*line));
		newl = ft_strjoin((*line), "\n");
		printf("line : |%s|", newl);
		j++;
	}

	return (0);
}