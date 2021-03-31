/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:32:45 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/31 16:17:08 by lmarzano         ###   ########.fr       */
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
	return (nwline);
}

int	ft_check_type(char **line, t_all *all)
{
	if (**line == 'R')
	{
		if (ft_parse_digit(line, all) == -1 && all->chr->r == 0)
				return (-1);
		all->chr->r++;
	}
	else if (**line == 'S' && *((*line) + 1) != 'O')
	{
		if ((all->par->sprite = ft_text_store(line)) == 0)
			return (-1);
		all->chr->s++;
	}
	else if (ft_check_walls(line, all) == 1)
		return (1);
	else
		return (-1);
	return (1);
}

int	ft_check_walls(char **line, t_all *all)
{
	if (**line == 'N' && *(++(*line)) == 'O')
	{
		if ((all->par->wall[0] = ft_text_store(line)) == 0)
			return (-1);
		all->chr->no++;
	}
	else if (**line == 'S' && *(++(*line)) == 'O')
	{
		if ((all->par->wall[1] = ft_text_store(line)) == 0)
			return (-1);
		all->chr->so++;
	}
	else if (**line == 'W' && *(++(*line)) == 'E')
	{
		if ((all->par->wall[2] = ft_text_store(line)) == 0)
			return (-1);
		all->chr->we++;
	}
	else if (**line == 'E' && *(++(*line)) == 'A')
	{
		if ((all->par->wall[3] = ft_text_store(line)) == 0)
			return (-1);
		all->chr->ea++;
	}
	return (1);
}


int	ft_parse_line(char *line, t_all *all)
{
	
	if (!line)
		return (1);
	while (*line)
	{
		if (*line == ' ')
			line++;
		else
		{
			if (ft_check_type(&line, all) == -1)
				return (-1);
			//if (ft_check_walls(&line, all) == -1)
			///	return (-1);
		}
		line++;//da eliminare una volta parsati tutti
	}
	//if (all->chr->mp != 1 || all->chr->r != 1 || all->chr->no != 1 || all->chr->so != 1\
	//|| all->chr->we != 1 || all->chr->ea != 1 || all->chr->s != 1 || all->chr->f != 1 || all->chr->c != 1)
    //    return (-1);
	return (1);
}