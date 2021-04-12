/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:02:37 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/12 10:07:07 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_cond(t_vars *vars)
{
	if (vars->drawStartY < 0)
		vars->drawStartY = 0;
	vars->drawEndY = vars->spriteHeight / 2 + vars->ScreenHeight / 2;
	if (vars->drawEndY >= vars->ScreenHeight)
		vars->drawEndY = vars->ScreenHeight - 1;
	vars->spriteWidth = abs((int)(vars->ScreenHeight / vars->transformY));
	vars->drawStartX = -vars->spriteWidth / 2 + vars->spriteScreenX;
	if (vars->drawStartX < 0)
		vars->drawStartX = 0;
	vars->drawEndX = vars->spriteWidth / 2 + vars->spriteScreenX;
	if (vars->drawEndX >= vars->ScreenWidth)
		vars->drawEndX = vars->ScreenWidth - 1;
	vars->stripe = vars->drawStartX;
}

int	ft_sprite_setmem(t_sprite *sprite, t_vars *vars, \
 int spriteOrder[vars->nSprites], double spriteDistance[vars->nSprites])
{
	int	i;

	i = 0;
	ft_getcoordinates(vars, sprite);
	while (i < vars->nSprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = (vars->posX - sprite[i].x) * (vars->posX - sprite[i].x) \
		 + (vars->posY - sprite[i].y) * (vars->posY - sprite[i].y);
		i++;
	}
	ft_sortsprites(spriteOrder, spriteDistance, vars->nSprites);
	return (0);
}

void	ft_cast_text(t_vars *vars, t_data *img, double *buffer)
{
	vars->texX = (int)(256 * (vars->stripe - (-vars->spriteWidth / 2 \
	 + vars->spriteScreenX)) * TEXWIDTH /vars->spriteWidth) / 256;
	if (vars->transformY > 0 && vars->stripe > 0 && vars->stripe < vars->ScreenWidth \
	 && vars->transformY < buffer[vars->stripe])
	{
		vars->y = vars->drawStartY;
		while (vars->y < vars->drawEndY)
		{
			vars->d = (vars->y) * 256 - vars->ScreenHeight * 128 + vars->spriteHeight *128;
			vars->texY = ((vars->d * TEXHEIGHT) / vars->spriteHeight) / 256;
			vars->color = vars->texture[6].colors[TEXWIDTH * vars->texY + vars->texX];
			if ((vars->color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(img, vars->stripe, vars->y, vars->color);
			vars->y++;
		}
	}
}

void	ft_spritecasting(t_vars *vars, t_data *img, double *buffer)
{
	t_sprite	*sprite;
	int			spriteOrder[vars->nSprites];
	double		spriteDistance[vars->nSprites];
	int			i;

	sprite = malloc(sizeof(t_sprite) * vars->nSprites);
	if (!sprite)
	{
		printf("Error\n");
		exit(0);
	}
	i = ft_sprite_setmem(sprite, vars, spriteOrder, spriteDistance);
	while (i < vars->nSprites)
	{
		vars->spriteX = sprite[spriteOrder[i]].x - vars->posX;
		vars->spriteY = sprite[spriteOrder[i]].y - vars->posY;
		vars->invDet = 1.0 / (vars->planeX * vars->dirY - vars->dirX * vars->planeY);
		vars->transformX = vars->invDet * (vars->dirY * vars->spriteX - vars->dirX * vars->spriteY);
		vars->transformY = vars->invDet * (-vars->planeY * vars->spriteX + vars->planeX * vars->spriteY);
		vars->spriteScreenX = (int)((vars->ScreenWidth / 2) * (1 + vars->transformX / vars->transformY));
		vars->spriteHeight = abs((int)(vars->ScreenHeight / vars->transformY));
		vars->drawStartY = -vars->spriteHeight / 2 + vars->ScreenHeight / 2;
		ft_draw_cond(vars);
		while (vars->stripe < vars->drawEndX)
		{
			ft_cast_text(vars, img, buffer);
			vars->stripe++;
		}
		i++;
	}
	free(sprite);
}

