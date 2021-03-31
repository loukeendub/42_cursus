/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:09:10 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/31 16:16:04 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_itoa(char **line, t_all *all, int h)
{
	if (h == 0)
	{
		while (ft_isdigit((**line)))
		{
			all->par->res_w = all->par->res_w * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}
	else if (h == 1)
	{
		while (ft_isdigit(**line))
		{
			all->par->res_h = all->par->res_h * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}			
	else 
		return (-1);
	return (h);
}

int	ft_parse_digit(char **line, t_all *all)
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
			while (ft_isdigit((**line)))
			{
				h = ft_itoa(line, all, h);
				if (h == -1)
					return (-1);
			}
		}
		else
			return (-1);
	}
	return (1);
}		