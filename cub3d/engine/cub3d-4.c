/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:00:40 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/02 15:30:57 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#define texWidth 64
#define texHeight 64



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

int		ft_iscinstr(char c, char const *str, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}