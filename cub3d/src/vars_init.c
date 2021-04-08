/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:08:15 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/08 16:38:59 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_tex(t_vars *vars, t_all *all)
{
	vars->ScreenHeight = all->par->res_h;
	vars->ScreenWidth = all->par->res_w;
	vars->map = all->par->map;
	vars->mapHeight = all->par->map_h;
	vars->nSprites = 0;
	vars->texture[0].path = all->par->wall[0];
	vars->texture[1].path = all->par->wall[1];
	vars->texture[2].path = all->par->wall[2];
	vars->texture[3].path = all->par->wall[3];
	vars->texture[6].path = all->par->sfc[0];
	vars->texture[4].path = all->par->sfc[1];
	vars->texture[5].path = all->par->sfc[2];
}

void	ft_rc_init(t_vars *vars, t_all *all, int i)
{
	int	j;

	j = 1;
	while (all->par->map[i][j])
	{
		if (all->par->map[i][j] == '2')
			vars->nSprites++;
		if (ft_iscinstr(all->par->map[i][j], "NWSE", 4))
		{
			vars->posX = i + 0.5;
			vars->posY = j + 0.5;
			vars->dir = all->par->map[i][j];
		}
		j++;
	}
}

void	ft_spawnNS_init(t_vars *vars)
{
	if (vars->dir == 'N')
	{
		vars->dirX = -1;
		vars->dirY = 0;
		vars->planeX = 0;
		vars->planeY = 0.66;
	}
	else if (vars->dir == 'S')
	{
		vars->dirX = 1;
		vars->dirY = 0;
		vars->planeX = 0;
		vars->planeY = -0.66;
	}
}

void	ft_spawnEW_init(t_vars *vars)
{
	if (vars->dir == 'E')
	{
		vars->dirX = 0;
		vars->dirY = 1;
		vars->planeX = 0.66;
		vars->planeY = 0;
	}
	else if (vars->dir == 'W')
	{
		vars->dirX = 0;
		vars->dirY = -1;
		vars->planeX = -0.66;
		vars->planeY = 0;
	}
}

void	ft_init_vars(t_vars *vars, t_all *all)
{
	int	i;

	i = 1;
	ft_init_tex(vars, all);
	while (all->par->map[i])
	{
		ft_rc_init(vars, all, i);
		i++;
	}
	if (vars->dir == 'N' || vars->dir == 'S')
		ft_spawnNS_init(vars);
	else if (vars->dir == 'E' || vars->dir == 'W')
		ft_spawnEW_init(vars);
}
