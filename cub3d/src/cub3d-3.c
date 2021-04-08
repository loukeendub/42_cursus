/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:49:37 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/08 09:29:24 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define TEXWIDTH 64
#define TEXHEIGHT 64

void	ft_keycode_fill(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->keyUp = 1;
	else if (keycode != 13)
		vars->keyUp = 0;
	if (keycode == 1)
		vars->keyDown = 1;
	else if (keycode != 1)
		vars->keyDown = 0;
	if (keycode == 123)
		vars->keyLeftView = 1;
	else if (keycode != 123)
		vars->keyLeftView = 0;
	if (keycode == 124)
		vars->keyRightView = 1;
	else if (keycode != 124)
		vars->keyRightView = 0;
	if (keycode == 0)
		vars->keyRight = 1;
	else if (keycode != 0)
		vars->keyRight = 0;
	if (keycode == 2)
		vars->keyLeft = 1;
	else if (keycode != 2)
		vars->keyLeft = 0;
}

int	key_hook(int keycode, t_vars *vars)
{
	ft_keycode_fill(keycode, vars);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		system("killall afplay");
		exit(0);
	}
	return (0);
}

int	ft_release(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->keyUp = 0;
	else if (keycode != 13)
		vars->keyUp = 1;
	if (keycode == 1)
		vars->keyDown = 0;
	else if (keycode != 1)
		vars->keyDown = 1;
	if (keycode == 123)
		vars->keyLeftView = 0;
	else if (keycode != 123)
		vars->keyLeftView = 1;
	if (keycode == 124)
		vars->keyRightView = 0;
	else if (keycode != 124)
		vars->keyRightView = 1;
	if (keycode == 0)
		vars->keyRight = 0;
	else if (keycode != 0)
		vars->keyRight = 1;
	if (keycode == 2)
		vars->keyLeft = 0;
	else if (keycode != 2)
		vars->keyLeft = 1;
	return (0);
}

void	ft_getcoordinates(t_vars *vars, t_sprite *sprite)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (x < vars->mapHeight)
	{
		while (vars->map[x][y])
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
	int		i;
	int		j;
	double	checkd;
	int		checko;

	i = 0;
	while (i < n)
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
