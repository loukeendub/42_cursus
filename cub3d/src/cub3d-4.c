/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:00:40 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/08 09:42:50 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define TEXWIDTH 64
#define TEXHEIGHT 64

void	ft_destroytextures(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->texture[0].img);
	mlx_destroy_image(vars->mlx, vars->texture[1].img);
	mlx_destroy_image(vars->mlx, vars->texture[2].img);
	mlx_destroy_image(vars->mlx, vars->texture[3].img);
	mlx_destroy_image(vars->mlx, vars->texture[4].img);
	mlx_destroy_image(vars->mlx, vars->texture[5].img);
	mlx_destroy_image(vars->mlx, vars->texture[6].img);
}

int	ft_iscinstr(char c, char const *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_floor(char **line, t_all *all)
{
	all->chr->f++;
	all->par->f = 'F';
	while (ft_isdigit(**line) == 0 && **line != '.')
		(*line)++;
	if (**line == '.')
	{
		(*line)--;
		all->par->sfc[1] = ft_text_store(line);
		all->par->floor[0] = 0;
		all->par->floor[1] = 0;
		all->par->floor[2] = 0;
	}
	else if (ft_isdigit(**line))
		return (ft_type_core(line, all, &all->chr->f, &all->par->f));
	else
		return (-1);
	return (1);
}

int	ft_ceiling(char **line, t_all *all)
{
	all->chr->c++;
	all->par->f = 'C';
	while (ft_isdigit(**line) == 0 && **line != '.')
		(*line)++;
	if (**line == '.')
	{
		(*line)--;
		all->par->sfc[2] = ft_text_store(line);
		all->par->ceiling[0] = 0;
		all->par->ceiling[1] = 0;
		all->par->ceiling[2] = 0;
	}
	else if (ft_isdigit(**line))
		return (ft_type_core(line, all, &all->chr->c, &all->par->f));
	else
		return (-1);
	return (1);
}
