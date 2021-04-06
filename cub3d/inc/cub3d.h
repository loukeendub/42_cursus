/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/06 12:41:38 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

/*
** structure
*/
typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

typedef struct  s_tex   {
	char    *path;
	void    *img;
	char    *addr;
	int     *colors;
	int     width;
	int     height;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               t_tex;

typedef	struct	s_parse
{
	int		res_w;
	int		res_h;
	int		sky[3];
	int		floor[3];
	int		ceiling[3];
	char	*wall[4];
	char	*sfc[3];
	char	**map;
	char	reference[8];
	int		spawn;
	int		map_h;
	char	f;
}				t_parse;

typedef struct	s_check
{
	int		r;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
	int		mp;
	int		space;
}				t_check;

typedef struct s_keys
{
  int  keyUp;
  int  keyDown;
  int  keyLeftView;
  int  keyRightView;
  int  keyLeft;
  int  keyRight;
}             t_keys;

typedef struct  s_sprite
{
	double  x;
	double  y;
}               t_sprite;

typedef struct  s_vars 
{
	void        *towD_win;
	void        *mlx;
	void        *win;
	int         x;
	int         y;
	double      posX;
	double      posY;  //x and y start position
	double      dirX;
	double      dirY; //initial direction vector
	double      planeX;
	double      planeY; //the 2d raycaster version of camera plane
	double      time; //time of current frame
	double      oldTime; //time of previous frame
	double      camX;
	double      camY;
	double      cameraX; //x-coordinate in camera space
	double      rayDirX;
	double      rayDirY;
	double      rayDirX0;
	double      rayDirX1;
	double      rayDirY0;
	double      rayDirY1;
	int         p;
	float       posZ;
	float       rowDistance;
	float       floorStepX;
	float       floorStepY;
	float       floorX;
	float       floorY;
	int         cellX;
	int         cellY;
	int         tx;
	int         ty;
	//which box of the map we're in
	int         mapX;
	int         mapY;

	//length of ray from current position to next x or y-side
	double      sideDistX;
	double      sideDistY;

	//length of ray from one x or y-side to next x or y-side
	double      deltaDistX;
	double      deltaDistY;
	double      perpWallDist;

	//what direction to step in x or y-direction (either +1 or -1)
	int         stepX;
	int         stepY;

	int         hit; //was there a wall hit?
	int         side; //was a NS or a EW wall hit?
	//calculate step and initial sideDist
	int         lineHeight;

	  //calculate lowest and highest pixel to fill in current stripe
	int         drawStart;
	int         drawEnd;
	double      frameTime;
	double      moveSpeed; //the constant value is in squares/second
	double      rotSpeed;
	double      oldDirX;
	double      oldPlaneX;
	t_tex       texture[7];
	int         textNum;
	double      wallX;
	int         texX;
	int         texY;
	double      step;
	double      texPos;
	int         color;
	//keys
	int  keyUp;
	int  keyDown;
	int  keyLeftView;
	int  keyRightView;
	int  keyLeft;
	int  keyRight;
	int  ScreenHeight;
	int  ScreenWidth;
	char    **map;
	int     mapHeight;
	int     mapWidth;
	int     nSprites;
	char    dir;
 //sprite
	double      spriteX;
	double      spriteY;
	double      invDet;
	double      transformX;
	double      transformY;
	int         spriteScreenX;
	int         spriteHeight;
	int         drawStartY;
	int         drawEndY;
	int         spriteWidth;
	int         drawStartX;
	int         drawEndX;
	int         stripe;
	int         d;
}               t_vars;
/*
** Struct pointers
*/
typedef struct	s_all
{
	t_parse		*par;
	t_check		*chr;
	t_data		*data;
	t_tex		*tex;
	t_sprite	*spr;
}				t_all;

/*
** init [FULL] [NORMA V3 OK]
*/
void			ft_str_all_init(t_all *all);
void			ft_struct_init(t_all *all);
void			ft_tx_init(t_all *all);
void			ft_ref_init(t_all *all);
void			ft_check_init(t_all *all);
/*
** parsing [FULL] [NORMA V3 OK]
*/
int				check_val(t_all *all);
int				ft_parse_line(char *line, int fd, t_all *all);
int				ft_check_walls(char **line, t_all *all);
int				ft_check_type(char **line, t_all *all);
char			*ft_text_store(char **line);
/*
** parsing2 [NORMA V3 OK]
*/
int				ft_parse_digit(char **line, t_all *all);
int				ft_parse_digit2(char **line, t_all *all);
int				ft_digit_core(char **line, t_all *all, int h, int count);
int				ft_treatfc(char **line, t_all *all, int h);
/*
** map_parsing [NORMA V3 OK]
*/
int				ft_map_parse(char **line, int fd, t_all *all);
int				ft_check_rows(char *newl, t_all *all);
int				ft_check_map(char **map, t_all *all);
int				ft_check_updown(char *first, char *last);
/*
** map_parsing2 [NORMA V3 OK]
*/
int				ft_check_line(char **map, int y, t_all *all);
int				ft_check_edges(char **map, int y);
int				ft_check_previous(char **map, int y, int x, int previous);
int				ft_check_current(char **map, int y, int x, int current);
/*
** GNL
*/
int				get_next_line(int fd, char **line);
int				ft_taccone_gnl(char **line);
int				ft_just_do_it(char **line, char *buffer);
/*
** utils [FULL]
*/
int				ft_isdigit(char c);
size_t			ft_strlen(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_realloc(char **line);
char			*ft_realloc_finale(char **line);
/*
** utils_2
*/
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t			ft_strcount(char *str, char c);
size_t			ft_strclen(char *s, char c);
char			**ft_split(char *s, char c, t_all *all);
/*
** utils_3
*/
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
int				ft_itoa(char **line, t_all *all, int h);
int				ft_itoa2(char **line, t_all *all, int h);
int				ft_itoa3(char **line, t_all *all, int h);
/*
** core
*/
int				ft_type_core(char **line, t_all *all, int *chr, char *f);
int				ft_wall_core(char **line, char **wall, int *chr);
void			ft_itoa_core(char **line, int *all);
int				ft_split_core(char *s, char **arr, char c, t_all *all);
int				ft_parse_line_core(char *line, int i, int ret, t_all *all);
/*
** cub3d
*/
void			ft_main_parsing(char *path, t_all *all);
void			ft_init_vars(t_vars *vars, t_all *all);
void			ft_spritecasting(t_vars *vars, t_data *img, double *buffer);
int 			render_next_frame(t_vars *vars);
/*
** cub3d-2 [FULL]
*/
int				ft_exit(t_vars *vars);
int				ft_gettexnum(t_vars *vars);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_keys(t_vars *vars);
int 			ft_keys2(t_vars *vars);
/*
** cub3d-3 [FULL]
*/
void			ft_gettextures(t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
int 			ft_release(int keycode, t_vars *vars);
void			ft_getcoordinates(t_vars *vars, t_sprite *sprite);
void			ft_sortsprites(int *order, double *distance, int n);
/*
** cub3d-4
*/
void			ft_destroytextures(t_vars *vars);
int				ft_iscinstr(char c, char const *str, size_t len);
int				ft_floor(char **line, t_all *all);
int				ft_ceiling(char **line, t_all *all);

#endif
