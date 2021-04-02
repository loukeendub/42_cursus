/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:32:45 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/02 12:18:41 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_text_store(char **line)
{
	int		j;
	char	*nwline;

	j = 0;
	(*line)++;
	while (**line != '.')
	{
		if (**line != ' ')
			return (0);
		(*line)++;
	}
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
	return (nwline);
}

int	ft_check_type(char **line, t_all *all)// 35 lines
{
	if (**line == 'R')
	{
		if (ft_parse_digit(line, all) == -1 && all->chr->r == 0)
				return (-1);
		all->chr->r++;
		return (1);
	}
	else if (**line == 'S' && *((*line) + 1) != 'O')
	{
		if ((all->par->sprite = ft_text_store(line)) == 0)
			return (-1);
		all->chr->s++;
		return (1);
	}
	else if (**line == 'F')
	{
		all->par->f = 'F';
		if (ft_parse_digit2(line, all) == -1)
				return (-1);
		all->chr->f++;
		return (1);
	}
	else if (**line == 'C')
	{
		all->par->f = 'C';
		if (ft_parse_digit2(line, all) == -1)
				return (-1);
		all->chr->c++;
		return (1);
	}
	else if (ft_check_walls(line, all) == 1)
		return (1);
	else
		return (-1);
	return (1);
}

int	ft_wall_core(char **line, char **wall, int *chr)
{
	puts(*line);
	*wall = ft_text_store(line);
	if (*wall == 0)
		return (-1);
	chr++;
	return (1);
}

int	ft_check_walls(char **line, t_all *all)
{
	if (**line == 'N' && *(++(*line)) == 'O')
		return (ft_wall_core(line, &all->par->wall[0], &all->chr->no));
	else if (**line == 'S' && *(++(*line)) == 'O')
		return (ft_wall_core(line, &all->par->wall[1], &all->chr->so));
	else if (**line == 'W' && *(++(*line)) == 'E')
		return (ft_wall_core(line, &all->par->wall[2], &all->chr->we));
	else if (**line == 'E' && *(++(*line)) == 'A')
		return (ft_wall_core(line, &all->par->wall[3], &all->chr->ea));
	return (1);
}

int	check_val(t_all *all)
{
	int i;

	i = 0;
	if (all->chr->r != 1 || all->chr->no != 1 || all->chr->so != 1 || all->chr->we != 1\
	|| all->chr->ea != 1 || all->chr->s != 1 || all->chr->f != 1 || all->chr->c != 1 || all->chr->mp != 1) 
		return (0);
	while (i < 3)
	{
		if (all->par->ceiling[i] < 0 || all->par->ceiling[i] > 255)
			return (0);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (all->par->floor[i] < 0 || all->par->floor[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_line(char *line, int fd, t_all *all)// >30 lines
{
	int ret;

	ret = 0;
	int i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		//puts(line);
		if (line[i] == ' ' && line[i])
		{
			i++;
		}
		else if ((line[i]) == '1' && line[i])
				return (ft_map_parse(&line, fd, all));
		else if (!ft_isdigit(line[i]))//da rivedere
		{
			while (i-- && *line)
				line++;
			ret = ft_check_type(&line, all);
			if (ret == -1)
				return (-1);
			else if (ret == 1)
				return (1);
			else 
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (1);
}
