#include "cub3d.h"

void	ft_main_parsing(char *path, t_all *all, t_vars *vars)
{
	char	*line;
	int		fd_map;
	int		ret = 0;

	fd_map = open(path, O_RDONLY);
	ft_str_all_init(all);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd_map, &line);
		if (ft_parse_line(line, fd_map, all) == -1 || ret == -1)
		{
			write(1, "Error\n", 6);
			ft_exit(vars, all);
		}
	}
	if (!check_val(all))
	{
		write(1, "Error\n", 6);
		ft_exit(vars, all);
	}
	free(line);
}

int		ft_gettextures(t_vars *vars) // <----------------segfault qui (non trova più i pathfiles)
{
	vars->texture[0].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[0].path, \
	 &vars->texture[0].width, &vars->texture[0].height);
//	vars->texture[0].img = mlx_xpm_file_to_image(vars->mlx, "./textures/a.xpm", \
//	 &vars->texture[0].width, &vars->texture[0].height);
	//puts(vars->texture[0].path);
	//./textures/a.xpm
	if (!vars->texture[0].img)
		return (0);
	vars->texture[0].addr = mlx_get_data_addr(vars->texture[0].img, &vars->texture[0].bits_per_pixel, \
	 &vars->texture[0].line_length, &vars->texture[0].endian);
	vars->texture[0].colors = (int *)vars->texture[0].addr;
//	vars->texture[0].colors = (int *)mlx_get_data_addr(vars->texture[0].img, &vars->texture[0].bits_per_pixel, \
//	 &vars->texture[0].line_length, &vars->texture[0].endian);
	vars->texture[1].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[1].path, \
	 &vars->texture[1].width, &vars->texture[1].height);
	vars->texture[1].addr = mlx_get_data_addr(vars->texture[1].img, &vars->texture[1].bits_per_pixel, \
	 &vars->texture[1].line_length, &vars->texture[1].endian);
	vars->texture[1].colors = (int *)mlx_get_data_addr(vars->texture[1].img, &vars->texture[1].bits_per_pixel, \
	 &vars->texture[1].line_length, &vars->texture[1].endian);
	vars->texture[2].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[2].path, \
	 &vars->texture[2].width, &vars->texture[2].height);
	vars->texture[2].addr = mlx_get_data_addr(vars->texture[2].img, &vars->texture[2].bits_per_pixel, \
	 &vars->texture[2].line_length, &vars->texture[2].endian);
	vars->texture[2].colors = (int *)mlx_get_data_addr(vars->texture[2].img, &vars->texture[2].bits_per_pixel, \
	 &vars->texture[2].line_length, &vars->texture[2].endian);
	vars->texture[3].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[3].path, \
	 &vars->texture[3].width, &vars->texture[3].height);
	vars->texture[3].addr = mlx_get_data_addr(vars->texture[3].img, &vars->texture[3].bits_per_pixel, \
	 &vars->texture[3].line_length, &vars->texture[3].endian);
	vars->texture[3].colors = (int *)mlx_get_data_addr(vars->texture[3].img, &vars->texture[3].bits_per_pixel, \
	 &vars->texture[3].line_length, &vars->texture[3].endian);
	vars->texture[4].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[4].path, \
	 &vars->texture[4].width, &vars->texture[4].height);
	vars->texture[4].addr = mlx_get_data_addr(vars->texture[4].img, &vars->texture[4].bits_per_pixel, \
	 &vars->texture[4].line_length, &vars->texture[4].endian);
	vars->texture[4].colors = (int *)mlx_get_data_addr(vars->texture[4].img, &vars->texture[4].bits_per_pixel, \
	 &vars->texture[4].line_length, &vars->texture[4].endian);
	vars->texture[5].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[5].path, \
	 &vars->texture[5].width, &vars->texture[5].height);
	vars->texture[5].addr = mlx_get_data_addr(vars->texture[5].img, &vars->texture[5].bits_per_pixel, \
	 &vars->texture[5].line_length, &vars->texture[5].endian);
	vars->texture[5].colors = (int *)mlx_get_data_addr(vars->texture[5].img, &vars->texture[5].bits_per_pixel, \
	 &vars->texture[5].line_length, &vars->texture[5].endian);
	vars->texture[6].img = mlx_xpm_file_to_image(vars->mlx, vars->texture[6].path, \
	 &vars->texture[6].width, &vars->texture[6].height);
	vars->texture[6].addr = mlx_get_data_addr(vars->texture[6].img, &vars->texture[6].bits_per_pixel, \
	 &vars->texture[6].line_length, &vars->texture[6].endian);
	vars->texture[6].colors = (int *)mlx_get_data_addr(vars->texture[6].img, &vars->texture[6].bits_per_pixel, \
	 &vars->texture[6].line_length, &vars->texture[6].endian);
	return(1);
}


void	ft_spritecasting(t_vars *vars, t_data *img, double *buffer)// 65 lines
{
	t_sprite	*sprite;
	int			spriteOrder[vars->nSprites];
	double		spriteDistance[vars->nSprites];
	int			i;

	i = 0;
	sprite = malloc(sizeof(t_sprite) * vars->nSprites);
	if (!sprite)
	{
		printf("Error\n");
		exit(0);
	}
	ft_getcoordinates(vars, sprite);
	while (i < vars->nSprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = (vars->posX - sprite[i].x) * (vars->posX - sprite[i].x) +(vars->posY - sprite[i].y) * (vars->posY - sprite[i].y);
		i++;
	}
	ft_sortsprites(spriteOrder, spriteDistance, vars->nSprites);
	i = 0;
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
		while (vars->stripe < vars->drawEndX)
		{
			vars->texX = (int)(256 * (vars->stripe - (-vars->spriteWidth / 2 + vars->spriteScreenX)) * TEXWIDTH /vars->spriteWidth) / 256;
			if (vars->transformY > 0 && vars->stripe > 0 && vars->stripe < vars->ScreenWidth && vars->transformY < buffer[vars->stripe])
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
			vars->stripe++;
		}
		i++;
	}
	free(sprite);
}

int render_next_frame(t_vars *vars)// 157 lines
{
	int w = vars->ScreenWidth;
	int h = vars->ScreenHeight;
	double	zbuffer[vars->ScreenWidth];

	t_data img;
	img.img = mlx_new_image(vars->mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	vars->x = 1;
	vars->y = 0;
	while (vars->y < h)
	{
	  vars->rayDirX0 = vars->dirX - vars->planeX;
	  vars->rayDirY0 = vars->dirY - vars->planeY;
	  vars->rayDirX1 = vars->dirX + vars->planeX;
	  vars->rayDirY1 = vars->dirY + vars->planeY;

	  vars->p = vars->y - h / 2;
	  vars->posZ = 0.5 * h;
	  vars->rowDistance = vars->posZ / vars->p;
	  vars->floorStepX = vars->rowDistance * (vars->rayDirX1 - vars->rayDirX0) / w;
	  vars->floorStepY = vars->rowDistance * (vars->rayDirY1 - vars->rayDirY0) / w;
	  vars->floorX = vars->posX + vars->rowDistance * vars->rayDirX0;
	  vars->floorY = vars->posY + vars->rowDistance * vars->rayDirY0;

	  while (vars->x < w)
	  {
		vars->cellX = (int)(vars->floorX);
		vars->cellY = (int)(vars->floorY);
		vars->tx = (int)(TEXWIDTH * (vars->floorX - vars->cellX )) & (TEXWIDTH - 1);
		vars->ty = (int)(TEXHEIGHT * (vars->floorY - vars->cellY )) & (TEXHEIGHT - 1);
		vars->floorX += vars->floorStepX;
		vars->floorY += vars->floorStepY;
		vars->color = vars->texture[4].colors[vars->texture[4].width * vars->ty + vars->tx];
			  my_mlx_pixel_put(&img, vars->x, vars->y, vars->color);
	  	vars->color = vars->texture[5].colors[vars->texture[5].width * vars->ty + vars->tx];
			  my_mlx_pixel_put(&img, vars->x, h - vars->y - 1, vars->color);
		vars->x++;
	  }
	  vars->x = 1;
	  vars->y++;
	}
	vars->x = 0;
	vars->y = 0;
	while (vars->x < w)
	{
	  //calculate ray position and direction
	  vars->cameraX = 2 * vars->x / (double)w - 1; //x-coordinate in camera space
	  vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX;
	  vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
	  //which box of the map we're in
	  vars->mapX = vars->posX;
	  vars->mapY = vars->posY;

	  //length of ray from current position to next x or y-side

	   //length of ray from one x or y-side to next x or y-side
	  // Alternative code for deltaDist in case division through zero is not supported
	  vars->deltaDistX = (vars->rayDirY == 0) ? 0 : ((vars->rayDirX == 0) ? 1 : fabs(1 / vars->rayDirX));
	  vars->deltaDistY = (vars->rayDirX == 0) ? 0 : ((vars->rayDirY == 0) ? 1 : fabs(1 / vars->rayDirY));

	  //what direction to step in x or y-direction (either +1 or -1)
	  vars->hit = 0; //was there a wall vars.hit?
	  //calculate step and initial sideDist
	  if (vars->rayDirX < 0)
	  {
		vars->stepX = -1;
		vars->sideDistX = (vars->posX - vars->mapX) * vars->deltaDistX;
	  }
	  else
	  {
		vars->stepX = 1;
		vars->sideDistX = (vars->mapX + 1.0 - vars->posX) * vars->deltaDistX;
	  }
	  if (vars->rayDirY < 0)
	  {
		vars->stepY = -1;
		vars->sideDistY = (vars->posY - vars->mapY) * vars->deltaDistY;
	  }
	  else
	  {
		vars->stepY = 1;
		vars->sideDistY = (vars->mapY + 1.0 - vars->posY) * vars->deltaDistY;
	  }
	  //perform DDA
//	  write(1, "loser2\n", 7);
	  while (vars->hit == 0)
		{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (vars->sideDistX < vars->sideDistY)
		{
		  vars->sideDistX += vars->deltaDistX;
		  vars->mapX += vars->stepX;
		  vars->side = 0;
		}
		else
		{
		  vars->sideDistY += vars->deltaDistY;
		  vars->mapY += vars->stepY;
		  vars->side = 1;
		}
		//Check if ray has vars.hit a wall
		if (vars->map[vars->mapX][vars->mapY] == '1') 
		{
			vars->hit = 1;
		}
	}
	  //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (vars->side == 0)
			{vars->perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->rayDirX;}
		else
	   		{vars->perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->rayDirY;}

	  //Calculate height of line to draw on screen
	  	vars->lineHeight = (h / vars->perpWallDist);

	  //calculate lowest and highest pixel to fill in current stripe
	  	vars->drawStart = -vars->lineHeight / 2 + h / 2;
	  	if (vars->drawStart < 0)
	  	{
			vars->drawStart = 0;
	  	}
	  	vars->drawEnd = vars->lineHeight / 2 + h / 2;
	  	if (vars->drawEnd >= h)
	  	{
		vars->drawEnd = h - 1;
	  	}
	  //ft_drawline(img, vars);
		if (vars->side == 0)
			vars->wallX = vars->posY + vars->perpWallDist * vars->rayDirY;

		else
			vars->wallX = vars->posX + vars->perpWallDist * vars->rayDirX;
		vars->textNum = ft_gettexnum(vars);
		vars->wallX -= floor(vars->wallX);
		vars->texX = (int)(vars->wallX * (double)TEXWIDTH);
		if (vars->side == 0 && vars->rayDirX > 0)
			vars->texX = TEXWIDTH - vars->texX - 1;
		if (vars->side == 1 && vars->rayDirY < 0)
			vars->texX = TEXWIDTH - vars->texX - 1;
		vars->step = 1.0 * TEXHEIGHT / vars->lineHeight;
		vars->texPos = (vars->drawStart - h / 2 + vars->lineHeight / 2) * vars->step;
		vars->y = vars->drawStart;
//		write(1, "loser3\n", 7);
		while (vars->y < vars->drawEnd)
		{
//			write(1, "loser4\n", 7);
			vars->texY = (int)vars->texPos & (vars->texture[vars->textNum].height - 1);
			vars->texPos += vars->step;
//			vars->color = 0x00FF0000;
			vars->color = vars->texture[vars->textNum].colors[vars->texture[vars->textNum].width * vars->texY + vars->texX];
			my_mlx_pixel_put(&img, vars->x, vars->y, vars->color);
			vars->y++;
		}
		zbuffer[vars->x] = vars->perpWallDist;
		vars->x++;
	  //draw the pixels of the stripe as a vertical line
	  //ft_drawline(img, vars);
	  //verLine(vars->x, vars->drawStart, vars->drawEnd);
	}
	ft_spritecasting(vars, &img, zbuffer);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	ft_keys(vars);
	ft_keys2(vars);
	return (0);
}

/*
int        main(int argc, char **argv)
{
	void    *mlx_ptr;
	void    *mlx_win;
	t_parse parse;
	t_vars vars;
	vars.time = 0;
	vars.oldTime = 0;

	map_parsing(argv[1], &parse);
	ft_init_vars(&vars, &parse);
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, vars.ScreenWidth, vars.ScreenHeight, "Cub3V");
	vars.mlx = mlx_ptr;
	vars.win = mlx_win;
	vars.moveSpeed = 0.11;
	vars.rotSpeed = 0.07;
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 3, 1L<<1, ft_release, &vars);
	mlx_hook(vars.win, 17, 1L<<5, ft_exit, &vars);
	mlx_loop_hook(mlx_ptr, render_next_frame, &vars);

	mlx_loop(mlx_ptr);
}
*/