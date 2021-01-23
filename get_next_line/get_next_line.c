/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:13 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/23 12:57:27 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static int	nextfd;
	int			i;
	char		*str_tmp;

	nextfd = 0;
	i = 0;
	if (!fd || !*line || !(*line = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (*line[i])
	{
		while (*line[i] != '\n')
		{
			str_tmp[i] = *line[i];
			i++;
		}
		str_tmp[i] = '\0';
		free(str_tmp);
		return (1);
	}
	return (0);
}
