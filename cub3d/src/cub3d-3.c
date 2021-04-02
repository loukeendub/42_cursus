/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:49:37 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/02 17:01:27 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define texWidth 64
#define texHeight 64

void	ft_gettextures(t_vars *vars)
{
	vars->texture[0].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[0].path, &vars->texture[0].width, &vars->texture[0].height);
	vars->texture[0].addr = mlx_get_data_addr(vars->texture[0].img, &vars->texture[0].bits_per_pixel, &vars->texture[0].line_length, &vars->texture[0].endian);
	vars->texture[0].colors = (int *)mlx_get_data_addr(vars->texture[0].img, &vars->texture[0].bits_per_pixel, &vars->texture[0].line_length, &vars->texture[0].endian);
	vars->texture[1].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[1].path, &vars->texture[1].width, &vars->texture[1].height);
	vars->texture[1].addr = mlx_get_data_addr(vars->texture[1].img, &vars->texture[1].bits_per_pixel, &vars->texture[1].line_length, &vars->texture[1].endian);
	vars->texture[1].colors = (int *)mlx_get_data_addr(vars->texture[1].img, &vars->texture[1].bits_per_pixel, &vars->texture[1].line_length, &vars->texture[1].endian);
	vars->texture[2].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[2].path, &vars->texture[2].width, &vars->texture[2].height);
	vars->texture[2].addr = mlx_get_data_addr(vars->texture[2].img, &vars->texture[2].bits_per_pixel, &vars->texture[2].line_length, &vars->texture[2].endian);
	vars->texture[2].colors = (int *)mlx_get_data_addr(vars->texture[2].img, &vars->texture[2].bits_per_pixel, &vars->texture[2].line_length, &vars->texture[2].endian);
	vars->texture[3].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[3].path, &vars->texture[3].width, &vars->texture[3].height);
	vars->texture[3].addr = mlx_get_data_addr(vars->texture[3].img, &vars->texture[3].bits_per_pixel, &vars->texture[3].line_length, &vars->texture[3].endian);
	vars->texture[3].colors = (int *)mlx_get_data_addr(vars->texture[3].img, &vars->texture[3].bits_per_pixel, &vars->texture[3].line_length, &vars->texture[3].endian);
	vars->texture[4].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[4].path, &vars->texture[4].width, &vars->texture[4].height);
	vars->texture[4].addr = mlx_get_data_addr(vars->texture[4].img, &vars->texture[4].bits_per_pixel, &vars->texture[4].line_length, &vars->texture[4].endian);
	vars->texture[4].colors = (int *)mlx_get_data_addr(vars->texture[4].img, &vars->texture[4].bits_per_pixel, &vars->texture[4].line_length, &vars->texture[4].endian);
	vars->texture[5].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[5].path, &vars->texture[5].width, &vars->texture[5].height);
	vars->texture[5].addr = mlx_get_data_addr(vars->texture[5].img, &vars->texture[5].bits_per_pixel, &vars->texture[5].line_length, &vars->texture[5].endian);
	vars->texture[5].colors = (int *)mlx_get_data_addr(vars->texture[5].img, &vars->texture[5].bits_per_pixel, &vars->texture[5].line_length, &vars->texture[5].endian);
	vars->texture[6].img = mlx_xpm_file_to_image(vars->mlx, "./textures/duckwithknife.xpm", &vars->texture[6].width, &vars->texture[6].height);
	vars->texture[6].addr = mlx_get_data_addr(vars->texture[6].img, &vars->texture[6].bits_per_pixel, &vars->texture[6].line_length, &vars->texture[6].endian);
	vars->texture[6].colors = (int *)mlx_get_data_addr(vars->texture[6].img, &vars->texture[6].bits_per_pixel, &vars->texture[6].line_length, &vars->texture[6].endian);
	printf("--->%s\n", vars->texture[0].path);
}

int		key_hook(int keycode, t_vars *vars)
{
  keycode == 13 ? vars->keyUp = 1 : 0;
  keycode == 1 ? vars->keyDown = 1 : 0;
  keycode == 123 ? vars->keyLeftView = 1 : 0;
  keycode == 124 ? vars->keyRightView = 1 : 0;
  keycode == 0 ? vars->keyRight = 1 : 0;
  keycode == 2 ? vars->keyLeft = 1 : 0;
 /*dont forget to free all mallocs*/
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		system("killall afplay");
		exit(0);
	}
	/*change the return value*/
	return (0);
}

int 	ft_release(int keycode, t_vars *vars)
{
  keycode == 13 ? vars->keyUp = 0 : 1;
  keycode == 1 ? vars->keyDown = 0 : 1;
  keycode == 123 ? vars->keyLeftView = 0 : 1;
  keycode == 124 ? vars->keyRightView = 0 : 1;
  keycode == 0 ? vars->keyRight = 0 : 1;
  keycode == 2 ? vars->keyLeft = 0 : 1;
  return 0;
}

void	ft_getcoordinates(t_vars *vars, t_sprite *sprite)
{
	int	x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while(x < vars->mapHeight)
	{
		while(vars->map[x][y])
		{
			if (vars->map[x][y] == '2')
			{
				sprite[i].x = x + 0.5;
				sprite[i].y = y + 0.5;
				i++;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_sortsprites(int *order, double *distance, int n)
{
	int	i;
	int j;
	double checkd;
	int checko;

	i = 0;
	while(i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (distance[i] < distance[j])
			{
				checkd = distance[i];
				checko = order[i];
				distance[i] = distance[j];
				order[i] = order[j];
				distance[j] = checkd;
				order[j] = checko;
			}
			j++;
		}
		i++;
	}
}
