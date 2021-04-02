/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:43:02 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/02 14:49:22 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#define texWidth 64
#define texHeight 64

int	ft_exit(int keycode, t_vars *vars)
{
	/*dont forget to free all mallocs*/
	system("killall afplay");
	exit(0);
}

int		ft_gettexnum(t_vars *vars)
{
	if (vars->side == 0)
	{
		if (vars->rayDirX > 0)
			return(0);
		else
			return(1);
	}
	else
	{
		if (vars->rayDirY < 0)
			return(2);
		else
			return(3);
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		ft_keys(t_vars *vars)
{  
	if(vars->keyUp == 1)//w
	{
		
	  if(ft_iscinstr(vars->map[(int)(vars->posX + vars->dirX * 0.4)][(int)(vars->posY)], "0NSWE", 5))
		vars->posX = vars->posX + vars->dirX * vars->moveSpeed;
	  if(ft_iscinstr(vars->map[(int)(vars->posX)][(int)(vars->posY + vars->dirY * 0.4)], "0NSWE", 5))
		vars->posY = vars->posY + vars->dirY * vars->moveSpeed;
	}
	if(vars->keyDown == 1)//s
	{
	  if(ft_iscinstr(vars->map[(int)(vars->posX - vars->dirX * 0.4)][(int)(vars->posY)], "0NSWE", 5))
		vars->posX -= vars->dirX * vars->moveSpeed;
	  if(ft_iscinstr(vars->map[(int)(vars->posX)][(int)(vars->posY - vars->dirY * 0.4)], "0NSWE", 5))
		vars->posY -= vars->dirY * vars->moveSpeed;
	}
	if(vars->keyLeftView == 1)//rot sx
	{
	  vars->oldDirX = vars->dirX;
	  vars->dirX = vars->dirX * cos(vars->rotSpeed) - vars->dirY * sin(vars->rotSpeed);
	  vars->dirY = vars->oldDirX * sin(vars->rotSpeed) + vars->dirY * cos(vars->rotSpeed);
	  vars->oldPlaneX = vars->planeX;
	  vars->planeX = vars->planeX * cos(vars->rotSpeed) - vars->planeY * sin(vars->rotSpeed);
	  vars->planeY = vars->oldPlaneX * sin(vars->rotSpeed) + vars->planeY * cos(vars->rotSpeed);
	}
	return (0);
}

int 	ft_keys2(t_vars *vars)
{
	if(vars->keyRightView == 1)//rot dx
	{
	  vars->oldDirX = vars->dirX;
	  vars->dirX = vars->dirX * cos(-vars->rotSpeed) - vars->dirY * sin(-vars->rotSpeed);
	  vars->dirY = vars->oldDirX * sin(-vars->rotSpeed) + vars->dirY * cos(-vars->rotSpeed);
	  vars->oldPlaneX = vars->planeX;
	  vars->planeX = vars->planeX * cos(-vars->rotSpeed) - vars->planeY * sin(-vars->rotSpeed);
	  vars->planeY = vars->oldPlaneX * sin(-vars->rotSpeed) + vars->planeY * cos(-vars->rotSpeed);
	}
	if (vars->keyLeft == 1)//d
	{
	  if(ft_iscinstr(vars->map[(int)(vars->posX + vars->planeX * 0.4)][(int)(vars->posY)], "0NSWE", 5))
		vars->posX = vars->posX + vars->planeX * vars->moveSpeed;
	  if(ft_iscinstr(vars->map[(int)(vars->posX)][(int)(vars->posY + vars->planeY * 0.4)], "0NSWE", 5))
		vars->posY = vars->posY + vars->planeY * vars->moveSpeed;
	}
	if (vars->keyRight == 1)//a
	{
	  if(ft_iscinstr(vars->map[(int)(vars->posX - vars->planeX * 0.4)][(int)(vars->posY)], "0NSWE", 5))
		vars->posX -= vars->planeX * vars->moveSpeed;
	  if(ft_iscinstr(vars->map[(int)(vars->posX)][(int)(vars->posY - vars->planeY * 0.4)], "0NSWE", 5))
		vars->posY -= vars->planeY * vars->moveSpeed;
	}
	return(0);
}
