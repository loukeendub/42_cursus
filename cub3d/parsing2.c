/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:09:10 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/01 10:02:46 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		ft_treatfc(char **line, t_all *all, int h)
{
	if (all->par->f == 'C')
		h = ft_itoa2(line, all, h);
	else if (all->par->f == 'F')
		h = ft_itoa3(line, all, h);
	return (h);
}

int	ft_parse_digit2(char **line, t_all *all)// 30 lines
{
	int	h;
	int count;

	count = 0;
	h = 0;
	(*line)++;
	while (**line)
	{
		if (**line == ' ')
			(*line)++;
		else if (**line == ',')
		{
			count++;
			(*line)++;
		}
		else if (ft_isdigit(**line))
		{
			while (ft_isdigit((**line)))
			{
				h = ft_treatfc(line, all, h);
				if (h == -1)
					return (-1);
			}
		}
		else
			return (-1);
	}
	if (count != 2)
		return (-1);
	return (1);
}