/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:19:48 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/28 16:26:59 by lmarzano         ###   ########.fr       */
/*   Updated: 2021/01/29 12:06:05 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	buffer[4096][BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || fd > 255 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (just_do_it(line, buffer[fd]))
	{
<<<<<<< HEAD
		*line =ft_realloc_finale(line);
=======
		*line = ft_realloc_finale(line);
>>>>>>> origin/main
		return (1);
	}
	while ((i = read(fd, buffer[fd], BUFFER_SIZE)) > 0)
	{
		buffer[fd][i] = '\0';
		if (just_do_it(line, buffer[fd]))
		{
<<<<<<< HEAD
			*line =ft_realloc_finale(line);
=======
			*line = ft_realloc_finale(line);
>>>>>>> origin/main
			return (1);
		}
	}
	if (i < 0)
		return (-1);
	just_do_it(line, buffer[fd]);
<<<<<<< HEAD
	*line =ft_realloc_finale(line);
=======
	*line = ft_realloc_finale(line);
>>>>>>> origin/main
	return (i);
}
