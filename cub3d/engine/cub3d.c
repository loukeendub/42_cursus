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
}

int	key_hook(int keycode, t_vars *vars)
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

int ft_release(int keycode, t_vars *vars)
{
  keycode == 13 ? vars->keyUp = 0 : 1;
  keycode == 1 ? vars->keyDown = 0 : 1;
  keycode == 123 ? vars->keyLeftView = 0 : 1;
  keycode == 124 ? vars->keyRightView = 0 : 1;
  keycode == 0 ? vars->keyRight = 0 : 1;
  keycode == 2 ? vars->keyLeft = 0 : 1;
  return 0;
}

void	check_init(void)
{
	g_check.r = 0;
	g_check.no = 0;
	g_check.so = 0;
	g_check.we = 0;
	g_check.ea = 0;
	g_check.s = 0;
	g_check.f = 0;
	g_check.c = 0;
	g_check.err = 1;
	
}

void	ref_init(t_parse *g_p)
{
	g_p->reference[0] = ' ';
	g_p->reference[1] = '0';
	g_p->reference[2] = '1';
	g_p->reference[3] = '2';
	g_p->reference[4] = 'N';
	g_p->reference[5] = 'S';
	g_p->reference[6] = 'E';
	g_p->reference[7] = 'W';
	g_p->map_h = -1;
}


void	struct_init(t_parse *g_p)
{
	//system("afplay sesso.mp3 &");
	g_p->res_w = 0;
	g_p->res_h = 0;
	g_p->n_wall[0] = 0;
	g_p->n_wall[1] = 0;
	g_p->n_wall[2] = 0;
	g_p->s_wall[0] = 0;
	g_p->s_wall[1] = 0;
	g_p->s_wall[2] = 0;
	g_p->w_wall[0] = 0;
	g_p->w_wall[1] = 0;
	g_p->w_wall[2] = 0;
	g_p->e_wall[0] = 0;
	g_p->e_wall[1] = 0;
	g_p->e_wall[2] = 0;
	g_p->sky[0] = 0;
	g_p->sky[1] = 0;
	g_p->sky[2] = 0;
	g_p->floor[0] = 0;
	g_p->floor[1] = 0;
	g_p->floor[2] = 0;
	g_p->ceiling[0] = 0;
	g_p->ceiling[1] = 0;
	g_p->ceiling[2] = 0;
	ref_init(g_p);
	check_init();
}

void	map_parsing(char *path, t_parse *g_p)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open(path, O_RDONLY);
	struct_init(g_p);
	while(i)
	{
		i = get_next_line(fd, &line);
		if (i == 1)
			i = parsing(&line, fd, g_p);
		else if (i == -1)
		{
			printf("Error\n");
			exit(0);
		}
	}
}

void       ft_init_vars(t_vars *vars, t_parse *g_p)
{
    int i;
    int j;

    i = 1;
    j = 1;

    vars->ScreenHeight = g_p->res_h;
    vars->ScreenWidth = g_p->res_w;
    vars->map = g_p->map;
    vars->mapHeight = g_p->map_h;
    vars->texture[0].path = g_p->wall[0];
	vars->texture[1].path = g_p->wall[1];
	vars->texture[2].path = g_p->wall[2];
	vars->texture[3].path = g_p->wall[3];
	vars->texture[4].path = g_p->sfc[1]; //floor
	vars->texture[5].path = g_p->sfc[2]; //ceiling
	vars->texture[6].path = g_p->sfc[0];

    while (i < vars->mapHeight)
    {
        while(g_p->map[i][j])
        {
            if (g_p->map[i][j] == '2')
                vars->nSprites++;
            if (ft_iscinstr(g_p->map[i][j], "NWSE", ft_strlen(g_p->map[i])))
            {
                vars->posX = i + 0.5;
                vars->posY = j + 0.5;
                vars->dir = g_p->map[i][j];
                break ;
            }
            j++;
        }
        j = 1;
        i++;
    }
    if (vars->dir == 'N')
	{
		vars->dirX = -1;
		vars->dirY = 0;
		vars->planeX = 0;
		vars->planeY = 0.66;
	}
	else if (vars->dir  == 'S')
	{
		vars->dirX = 1;
		vars->dirY = 0;
		vars->planeX = 0;
		vars->planeY = -0.66;
	}
	else if (vars->dir  == 'E')
	{
		vars->dirX = 0;
		vars->dirY = 1;
		vars->planeX = 0.66;
		vars->planeY = 0;
	}
	else if (vars->dir  == 'W')
	{
		vars->dirX = 0;
		vars->dirY = -1;
		vars->planeX = -0.66;
		vars->planeY = 0;
	}
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

void	ft_spritecasting(t_vars *vars, t_data *img, double *buffer)
{
	t_sprite	*sprite;
	int			spriteOrder[vars->nSprites];
	double		spriteDistance[vars->nSprites];
	int			i;

	i = 0;
	if (!(sprite = malloc(sizeof(t_sprite) * vars->nSprites)))
	{
		printf("Error\n");
		exit(0);
	}
	ft_getcoordinates(vars, sprite);
	while(i < vars->nSprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = (vars->posX - sprite[i].x) * (vars->posX - sprite[i].x) +(vars->posY - sprite[i].y) * (vars->posY - sprite[i].y);
		i++;
	}
	ft_sortsprites(spriteOrder, spriteDistance, vars->nSprites);
	i = 0;
	while(i < vars->nSprites)
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
		while(vars->stripe < vars->drawEndX)
		{
			vars->texX = (int)(256 * (vars->stripe - (-vars->spriteWidth / 2 + vars->spriteScreenX)) * texWidth /vars->spriteWidth) / 256;
			if (vars->transformY > 0 && vars->stripe > 0 && vars->stripe < vars->ScreenWidth && vars->transformY < buffer[vars->stripe])
			{
				vars->y = vars->drawStartY;
				while (vars->y < vars->drawEndY)
				{
					vars->d = (vars->y) * 256 - vars->ScreenHeight * 128 + vars->spriteHeight *128;
					vars->texY = ((vars->d * texHeight) / vars->spriteHeight) / 256;
					vars->color = vars->texture[6].colors[texWidth * vars->texY + vars->texX];
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

int render_next_frame(t_vars *vars)
{
    int w = vars->ScreenWidth;
    int h = vars->ScreenHeight;
	double	zbuffer[vars->ScreenWidth];

    t_data img;
    img.img = mlx_new_image(vars->mlx, w, h);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    ft_gettextures(vars);
//floor and ceiling
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
        vars->tx = (int)(texWidth * (vars->floorX - vars->cellX )) & (texWidth - 1);
        vars->ty = (int)(texHeight * (vars->floorY - vars->cellY )) & (texHeight - 1);
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
    while(vars->x < w)
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
      if(vars->rayDirX < 0)
      {
        vars->stepX = -1;
        vars->sideDistX = (vars->posX - vars->mapX) * vars->deltaDistX;
      }
      else
      {
        vars->stepX = 1;
        vars->sideDistX = (vars->mapX + 1.0 - vars->posX) * vars->deltaDistX;
      }
      if(vars->rayDirY < 0)
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
      while (vars->hit == 0)
    	{
        //jump to next map square, OR in x-direction, OR in y-direction
        if(vars->sideDistX < vars->sideDistY)
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
        if(vars->map[vars->mapX][vars->mapY] == '1') 
        {
        	vars->hit = 1;
        }
    }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
    	if(vars->side == 0)
        	{vars->perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->rayDirX;}
    	else
       		{vars->perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->rayDirY;}

      //Calculate height of line to draw on screen
      	vars->lineHeight = (h / vars->perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      	vars->drawStart = -vars->lineHeight / 2 + h / 2;
      	if(vars->drawStart < 0)
      	{
        	vars->drawStart = 0;
      	}
      	vars->drawEnd = vars->lineHeight / 2 + h / 2;
      	if(vars->drawEnd >= h)
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
		vars->texX = (int)(vars->wallX * (double)texWidth);
		if (vars->side == 0 && vars->rayDirX > 0)
			vars->texX = texWidth - vars->texX - 1;
		if (vars->side == 1 && vars->rayDirY < 0)
			vars->texX = texWidth - vars->texX - 1;
		vars->step = 1.0 * texHeight / vars->lineHeight;
		vars->texPos = (vars->drawStart - h / 2 + vars->lineHeight / 2) * vars->step;
		vars->y = vars->drawStart;
		while (vars->y < vars->drawEnd)
		{
			vars->texY = (int)vars->texPos & (vars->texture[vars->textNum].height - 1);
			vars->texPos += vars->step;
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
    mlx_destroy_image(vars->mlx, img.img);
	ft_destroytextures(vars);
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