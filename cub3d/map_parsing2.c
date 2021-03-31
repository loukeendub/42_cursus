/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:49:13 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/31 17:35:52 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_current(char **map, int y, int x, int current)
{
	x = current + 1;
	while (map[y-1][x])
	{
		if (map[y-1][x] != '1' && map[y-1][x] != ' ')
			return (-1);
		x++;
	}
	return (1);
}

int		ft_check_previous(char **map, int y, int x, int previous)
{
	x = previous + 1;
	while (map[y][x])
	{
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (-1);
		x++;
	}
	return (1);
}

int		ft_check_edges(char **map, int y)
{
	int		current;
	int		previous;
	int		x;
	int		ch;

	x = 0;
	current = ft_strlen(map[y]) -1;
	previous = ft_strlen (map[y - 1]) - 1;
	if (current < previous)
		ch = ft_check_current(map, y, x, current);
	else if (current > previous)
		ch = ft_check_previous(map, y, x, previous);
	if (ch == -1)
			return (-1);
	return (1);
}

int		ft_check_line(char **map, int y, t_all *all)
{
	int		x;
	char	c;

	x = 0;
	if (ft_check_edges(map, y) == -1)
		return (-1);
	while (map[y][x])
	{
		c = map[y][x];
		if (c == 'W' || c == 'E' || c == 'S' || c == 'N')
			all->par->spawn++;
		if (c != '1' && c != 'W' && c != 'E' && c != 'S' && c != 'N' && c != '2' && c != '0' && c != ' ')
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		x++;
	}
	return (1);
}