/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:29:10 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/01 13:53:05 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_updown(char *first, char *last)
{
	int		i = 0;
	while (first[i])
	{
		if (first[i] != '1' && first[i] != ' ')
			return(-1);
		i++;
	}
	i = 0;
	while (last[i])
	{
		if (last[i] != '1' && last[i] != ' ')
			return(-1);
		i++;
	}
	return (1);
}

int		ft_check_map(char **map, t_all *all)
{
	int		i = 1;
	int		len;
	if (ft_check_updown(map[0], map[all->par->map_h]) == -1)
		return (-1);
	while (i < all->par->map_h)
	{
		len = ft_strlen(map[i]) - 1;
		if ((map[i][0] != '1' && map[i][0] != ' ') || (map[i][len] != '1' && map[i][len] != ' '))
			return (-1);
		i++;
	}
	i = 1;
	while (i <= all->par->map_h)
	{
		if (ft_check_line(map, i++, all) == -1)
		  return (-1);
	}
	if (all->par->spawn != 1)
		return (-1);
	return (1);
}

int		ft_check_rows(char *newl, t_all *all)
{
	int		y;
	int		i;
	y = 0;
	i = 0;
	while (newl[y])
	{
		if (newl[y] == 'X')
			i++;
		if (newl[y] == 'X' && newl[y + 1] == 'X' && i < all->par->map_h + 1)
			return (-1);
			y++;
	}
	return (1);
}

int		ft_map_parse(char **line, int fd, t_all *all)
{
	int		i;
	int		y;
	char	*newl;

	i = 1;
	y = 0;
	newl = ft_strjoin((*line), "X");
	while (i > 0)
	{
		i = get_next_line(fd, line);
		newl = ft_strjoin(newl, (*line));
		newl = ft_strjoin(newl, "X");
	}
	
	all->par->map = ft_split(newl, 'X', all);//fin qui tutto ok
	if (ft_check_rows(newl, all) == -1 || ft_check_map(all->par->map, all) == -1)
		return (-1);
	else
		all->chr->mp = 1;
	free(newl);
	return (1);
}
