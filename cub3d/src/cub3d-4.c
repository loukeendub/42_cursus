/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:00:40 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/07 15:02:57 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define TEXWIDTH 64
#define TEXHEIGHT 64

void	ft_destroytextures(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->texture[0].img);// <-----il segfault avviene qui dentro
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
	}
	else if (ft_isdigit(**line))
		return (ft_type_core(line, all, &all->chr->c, &all->par->f));
	else
		return (-1);
	return (1);
}
/*
void	ft_gettextures(t_vars *vars)
{
	vars->texture[0].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[0].path, \
	 &vars->texture[0].width, &vars->texture[0].height);
	vars->texture[0].addr = mlx_get_data_addr(vars->texture[0].img, &vars->texture[0].bits_per_pixel, \
	 &vars->texture[0].line_length, &vars->texture[0].endian);
	//vars->texture[0].colors = (int *)mlx_get_data_addr(vars->texture[0].img, &vars->texture[0].bits_per_pixel, \
	// &vars->texture[0].line_length, &vars->texture[0].endian);
	//vars->texture[1].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[1].path, \
	// &vars->texture[1].width, &vars->texture[1].height);
	//vars->texture[1].addr = mlx_get_data_addr(vars->texture[1].img, &vars->texture[1].bits_per_pixel, \
	// &vars->texture[1].line_length, &vars->texture[1].endian);
	//vars->texture[1].colors = (int *)mlx_get_data_addr(vars->texture[1].img, &vars->texture[1].bits_per_pixel, \
	// &vars->texture[1].line_length, &vars->texture[1].endian);
	//vars->texture[2].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[2].path, \
	// &vars->texture[2].width, &vars->texture[2].height);
	//vars->texture[2].addr = mlx_get_data_addr(vars->texture[2].img, &vars->texture[2].bits_per_pixel, \
	// &vars->texture[2].line_length, &vars->texture[2].endian);
	//vars->texture[2].colors = (int *)mlx_get_data_addr(vars->texture[2].img, &vars->texture[2].bits_per_pixel, \
	// &vars->texture[2].line_length, &vars->texture[2].endian);
	//vars->texture[3].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[3].path, \
	// &vars->texture[3].width, &vars->texture[3].height);
	//vars->texture[3].addr = mlx_get_data_addr(vars->texture[3].img, &vars->texture[3].bits_per_pixel, \
	// &vars->texture[3].line_length, &vars->texture[3].endian);
	//vars->texture[3].colors = (int *)mlx_get_data_addr(vars->texture[3].img, &vars->texture[3].bits_per_pixel, \
	// &vars->texture[3].line_length, &vars->texture[3].endian);
	//vars->texture[4].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[4].path, \
	// &vars->texture[4].width, &vars->texture[4].height);
	//vars->texture[4].addr = mlx_get_data_addr(vars->texture[4].img, &vars->texture[4].bits_per_pixel, \
	// &vars->texture[4].line_length, &vars->texture[4].endian);
	//vars->texture[4].colors = (int *)mlx_get_data_addr(vars->texture[4].img, &vars->texture[4].bits_per_pixel, \
	// &vars->texture[4].line_length, &vars->texture[4].endian);
	//vars->texture[5].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[5].path, \
	// &vars->texture[5].width, &vars->texture[5].height);
	//vars->texture[5].addr = mlx_get_data_addr(vars->texture[5].img, &vars->texture[5].bits_per_pixel, \
	// &vars->texture[5].line_length, &vars->texture[5].endian);
	//vars->texture[5].colors = (int *)mlx_get_data_addr(vars->texture[5].img, &vars->texture[5].bits_per_pixel, \
	// &vars->texture[5].line_length, &vars->texture[5].endian);
	//vars->texture[6].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[6].path, \
	// &vars->texture[6].width, &vars->texture[6].height);
	//vars->texture[6].addr = mlx_get_data_addr(vars->texture[6].img, &vars->texture[6].bits_per_pixel, \
	// &vars->texture[6].line_length, &vars->texture[6].endian);
	//vars->texture[6].colors = (int *)mlx_get_data_addr(vars->texture[6].img, &vars->texture[6].bits_per_pixel, \
	// &vars->texture[6].line_length, &vars->texture[6].endian);
}
*/