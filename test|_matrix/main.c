/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:36:36 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/19 16:12:53 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	BUFFER_SIZE = 4095;

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

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

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	len;
	char	**arr;

	if (!s)
		return (NULL);
	if (!(arr = malloc(sizeof(s) * (ft_strcount(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_strclen(s, c);
			if (!(arr[i] = malloc(len + 1)))
				return (NULL);
			ft_strlcpy(arr[i], s, len + 1);
			s += len;
			i++;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

char	*ft_realloc(char **line)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(ft_strlen(*line) + BUFFER_SIZE + 1)))
		return (NULL);
	if (*line)
	{
		while ((*line)[i])
		{
			new[i] = (*line)[i];
			i++;
		}
		free(*line);
		*line = NULL;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_realloc_finale(char **line)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(ft_strlen(*line) + 1)))
		return (NULL);
	if (*line)
	{
		while ((*line)[i])
		{
			new[i] = (*line)[i];
			i++;
		}
		free(*line);
		*line = NULL;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
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

char	*ft_strjoin(char *s1, char *s2)
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

int	just_do_it(char **line, char *buffer)
{
	int	j;
	int	i;
	int len;

	j = 0;
	i = 0;
	*line = ft_realloc(line);
	len = ft_strlen(*line);
	while (buffer[j] && buffer[j] != '\n')
	{
		(*line)[len + j] = buffer[j];
		j++;
	}
	(*line)[len + j] = '\0';
	if (!buffer[j])
	{
		buffer[0] = 0;
		return (0);
	}
	j++;
	while (buffer[j])
		buffer[i++] = buffer[j++];
	buffer[i] = '\0';
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[1024][1024];
	int			i;

	if (fd < 0 || fd > 255 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (just_do_it(line, buffer[fd]))
	{
		*line = ft_realloc_finale(line);
		return (1);
	}
	while ((i = read(fd, buffer[fd], BUFFER_SIZE)) > 0)
	{
		buffer[fd][i] = '\0';
		if (just_do_it(line, buffer[fd]))
		{
			*line = ft_realloc_finale(line);
			return (1);
		}
	}
	if (i < 0)
		return (-1);
	just_do_it(line, buffer[fd]);
	*line = ft_realloc_finale(line);
	return (i);
}


int	main(void)
{
	char	**map;
	char	*line;
	char	*newl;
	int		fd;
	int		i;
	int		j;
	int		rd;

	fd = open("matrix.cub", O_RDONLY);
	i = 1;
	j = 0;
	i = get_next_line(fd, &line);
	newl = ft_strjoin(line, "F");
	while (1)
	{
		i = get_next_line(fd, &line);
		newl = ft_strjoin(newl, line);
		newl = ft_strjoin(newl, "F");
		if (i <= 0)
			break ;
	}
	map = ft_split(newl, 'F');
	printf("line : |%s|\n\n", newl);
	while (map[j] != 0)
	{
		printf("|%s|\n", map[j]);
		j++;
	}
	return (0);
}