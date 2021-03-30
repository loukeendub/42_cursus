/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:32:45 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 17:36:31 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_res(char **line)
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
		(*line)++;
	}
	g_check.r++;
	return (1);
}


int	check_type(char **line)
{
	if (**line == 'R')
		if (check_res(line) == -1)
				return (-1);
	return (1);
}

int	parse_line(char *line)
{
	
	if (!line)
		return (1);
	while (*line)
	{
		if (*line == ' ')
			line++;
		else
		{
			if (check_type(&line) == -1)
				return (-1);
		}
	}
	//if (g_check.mp != 1 || g_check.r != 1 || g_check.no != 1 || g_check.so != 1 ||\
	//g_check.we != 1 || g_check.ea != 1 || g_check.s != 1 || g_check.f != 1 || g_check.c != 1)
    //    return (-1);
	return (1);
}