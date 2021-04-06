/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:19:12 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/06 12:37:38 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_just_do_it(char **line, char *buffer)
{
	int	j;
	int	i;
	int	len;

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
int	ft_taccone_gnl(char **line)
{
	*line = ft_realloc_finale(line);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || fd > 255 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (ft_just_do_it(line, buffer[fd]))
		return (ft_taccone_gnl(line));
	i = read(fd, buffer[fd], BUFFER_SIZE);
	while (i > 0)
	{
		buffer[fd][i] = '\0';
		if (ft_just_do_it(line, buffer[fd]))
			return (ft_taccone_gnl(line));
	}
	if (i < 0)
		return (-1);
	ft_just_do_it(line, buffer[fd]);
	*line = ft_realloc_finale(line);
	return (i);
}
