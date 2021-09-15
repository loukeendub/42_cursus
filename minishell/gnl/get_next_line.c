/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:32:33 by jfabi             #+#    #+#             */
/*   Updated: 2021/04/28 11:13:53 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first_allocation(char *buffer)
{
	int		i;
	char	*p;

	i = 0;
	if (buffer == 0)
		return (0);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	p = malloc(i + 1);
	if (p == 0)
		return (0);
	p[0] = 0;
	return (p);
}

char	*allocazione_line(char *p, char *buffer)
{
	char	*temp;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (ft_strlenn(p) + 1));
	if (temp == 0)
		return (NULL);
	copia(temp, p);
	if (p != 0)
		free(p);
	p = malloc(sizeof(char) * (ft_strlenn(temp) + i + 1));
	if (p == 0)
		return (NULL);
	i = 0;
	while (temp[i] != 0)
	{
		p[i] = temp[i];
		i++;
	}
	p[i] = 0;
	free(temp);
	temp = 0;
	return (p);
}

char	*first_matrix_fd(char *matrix)
{
	int	i;

	i = 0;
	matrix = (char *)malloc(sizeof(char) * 32 + 1);
	if (matrix == 0)
		return (0);
	while (i <= 32)
		matrix[i++] = 0;
	return (matrix);
}

char	*join_modificato(char *p, char **matrix, int fd, int *ret)
{
	int	i;
	int	j;
	int	k;

	j = ft_strlenn(p);
	i = 0;
	*ret = 0;
	while (matrix[fd][i] != 0 && matrix[fd][i] != '\n')
	{
		p[i + j] = matrix[fd][i];
		i++;
	}
	p[i + j] = 0;
	if (matrix[fd][i] == '\n')
	{
		*ret = 1;
		i++;
	}
	k = 0;
	while (matrix[fd][i] != 0)
		matrix[fd][k++] = matrix[fd][i++];
	while (matrix[fd][k] != 0)
		matrix[fd][k++] = 0;
	matrix[fd][k] = 0;
	return (p);
}

int	ft_get_next_line(int fd, char **line)
{
	static char	*matrix[255];
	int			ret;

	if (fd < 0 || fd > 255 || 32 <= 0 || line == 0)
		return (-1);
	if (matrix[fd] == 0)
		matrix[fd] = first_matrix_fd(matrix[fd]);
	*line = first_allocation(matrix[fd]);
	if (*line == 0)
		return (-1);
	*line = join_modificato(*line, matrix, fd, &ret);
	if (ret == 1)
		return (1);
	while (read(fd, matrix[fd], 32) > 0)
	{
		*line = allocazione_line(*line, matrix[fd]);
		if (*line == 0)
			return (-1);
		*line = join_modificato(*line, matrix, fd, &ret);
		if (ret == 1)
			return (1);
	}
	free(matrix[fd]);
	matrix[fd] = 0;
	return (ret);
}
