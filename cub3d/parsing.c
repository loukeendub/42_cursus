/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:32:45 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 18:42:42 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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


int	ft_check_type(char **line)
{
	//printf("%c\n", **line);
	if (**line == 'R')
	{
		if (ft_check_res(line) == -1)
				return (-1);
	}
	else if (**line == 'N' && *(++(*line)) == 'O')
		printf("%s\n", *line);// integrare NO al posto del printf
	else if (**line == 'S' && *(++(*line)) == 'O')
		printf("%s\n", *line);// integrare SO al posto del printf
	else if (**line == 'W' && *(++(*line)) == 'E')
		printf("%s\n", *line);// integrare WE al posto del printf
	else if (**line == 'E' && *(++(*line)) == 'A')
		printf("%s\n", *line);// integrare EA al posto del printf
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
		}
		line++;//da eliminare una volta parsati tutti
	}
	//if (g_check.mp != 1 || g_check.r != 1 || g_check.no != 1 || g_check.so != 1 ||\
	//g_check.we != 1 || g_check.ea != 1 || g_check.s != 1 || g_check.f != 1 || g_check.c != 1)
    //    return (-1);
	return (1);
}