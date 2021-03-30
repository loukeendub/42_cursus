/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:32:45 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 19:55:11 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_text_store(char **line)
{
	int		j;
	char	*nwline;

	j = 0;
	while (**line != '.')
		(*line)++;
	if (**line == 0)
		return (0);
	else 
	{
		if (!(nwline = malloc(ft_strlen(*line) + 1)))
			return (0);
		while (**line && **line != ' ')
			nwline[j++] = *((*line)++);
		nwline[j] = 0;
	}
	///free(line); // mi dava errore, l'ho liberata nel main.
	return (nwline);
}

int		ft_check_res(char **line)
{
	int	h;

	h = 0;
	(*line)++;
	while (**line)
	{
		if (**line == ' ')
			(*line)++;
		else if (ft_isdigit(**line))
		{
			if (h == 0)
			{
				while (ft_isdigit((**line)))
				{
					g_p.res_w = g_p.res_w * 10 + ((int)(**line) - 48);
					(*line)++;
				}
				h++;
			}
			else if (h == 1)
			{
				while (ft_isdigit(**line))
				{
					g_p.res_h = g_p.res_h * 10 + ((int)(**line) - 48);
					(*line)++;
				}
				h++;
			}			
			else 
				return (-1);
		}
		else
			return (-1);
	}
	g_check.r++;
	return (1);
}

int	ft_check_type2(char **line)
{
	printf("%c\n", **line);
	if (**line == 'E' && *(++(*line)) == 'A')
	{
		if ((g_p.wall[3] = ft_text_store(line)) == 0)
			return (-1);
		g_check.ea++;
	}
	else if (**line == 'S')
	{
		if ((g_p.sprite = ft_text_store(line)) == 0)
			return (-1);
		g_check.s++;
	}
	return (1);
}

int	ft_check_type(char **line)
{
	//printf("%c\n", **line);
	if (**line == 'R')
	{
		if (ft_check_res(line) == -1)
				return (-1);
	}
	else if (**line == 'N' && *(++(*line)) == 'O')
	{
		if ((g_p.wall[0] = ft_text_store(line)) == 0)
			return (-1);
		g_check.no++;
	}
	else if (**line == 'S' && *(++(*line)) == 'O')
	{
		if ((g_p.wall[1] = ft_text_store(line)) == 0)
			return (-1);
		g_check.so++;
	}
	else if (**line == 'W' && *(++(*line)) == 'E')
	{
		if ((g_p.wall[2] = ft_text_store(line)) == 0)
			return (-1);
		g_check.we++;
	}

	return (1);
}

int	ft_parse_line(char *line)
{
	
	if (!line)
		return (1);
	while (*line)
	{
		if (*line == ' ')
			line++;
		else
		{
			if (ft_check_type(&line) == -1)
				return (-1);
			if (ft_check_type2(&line) == -1)
				return (-1);
		}
		line++;//da eliminare una volta parsati tutti
	}
	//if (g_check.mp != 1 || g_check.r != 1 || g_check.no != 1 || g_check.so != 1 ||\
	//g_check.we != 1 || g_check.ea != 1 || g_check.s != 1 || g_check.f != 1 || g_check.c != 1)
    //    return (-1);
	return (1);
}