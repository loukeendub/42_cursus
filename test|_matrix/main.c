/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:36:36 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/18 19:01:31 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

char	*ft_realloc(char **line)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(ft_strlen(*line) + 1 + 1)))
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
	static char	buffer[4096][1 + 1];
	int			i;

	if (fd < 0 || fd > 255 || !line || 1 <= 0)
		return (-1);
	*line = NULL;
	if (just_do_it(line, buffer[fd]))
	{
		*line = ft_realloc_finale(line);
		return (1);
	}
	while ((i = read(fd, buffer[fd], 1)) > 0)
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
/*
** fin qui è GNL, da qui inizia il parsing della matrice dal file matrix.cub
*/
//void	map_init(void)
//{
//	
//}
/*
** main
*/
int	main(void)
{
	char	**map;
	char	**line;
	int		fd_map;
	int		i;
	int		j;
	int		rd;

	fd_map = open("matrix.cub", O_RDONLY);
	i = 1;
	j = -1;
	//map_init();
	while (i)
	{
		i = get_next_line(fd_map, line);
	}
	return (0);
}