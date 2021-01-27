/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:19:48 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/27 17:29:26 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		(*line)[j + len] = buffer[j];
		j++;
	}
	line[0][j + len] = '\0';
	if (buffer[j] == '\n')
		j++;
	while (buffer[j] && buffer[j] != '\0')
		buffer[i++] = buffer[j++];
	if (i == 0)
	{
		buffer[0] = 0;
		return (0);
	}
	buffer[i] = '\0';
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (just_do_it(line, buffer))
		return (1);
	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = '\0';
		if (just_do_it(line, buffer))
			return (1);
	}
	return (0);
}
