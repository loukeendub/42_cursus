/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 18:42:06 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** structure
*/
typedef	struct	s_parse
{
	int		res_w;
	int		res_h;
	int		sky[3];
	int		floor[3];
	int		ceiling[3];
	char	*wall[4];
	char	*sfc[3];
	char	*sprite;
	char	**map;
	char	reference[8];
	int		spawn;
	int		map_h;
}				t_parse;
t_parse			g_p;

typedef struct	s_checker
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
}				t_checker;
t_checker		g_check;
/*
** old functions
*/
int				get_next_line(int fd, char **line);
int				just_do_it(char **line, char *buffer);
/*
** utils [FULL]
*/
int				ft_isdigit(int c);
size_t			ft_strlen(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_realloc(char **line);
char			*ft_realloc_finale(char **line);
/*
** utils_2 [FULL]
*/
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t			ft_strcount(char *str, char c);
size_t			ft_strclen(char *s, char c);
char			**ft_split(char *s, char c);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
/*
** parsing [FULL]
*/
int				parsing(char **line, int fd);// 31 lines
int				res_parse(char **line);// 27 lines
int				rgb_parse(char **line, int rgb[3]);
int				parse_wall(char **line, int j);
int				parse_sfc(char **line, int j);
/*
** map_parsing [FULL]
*/
int				map_parse(char **line, int fd);
char			*wall_store(char **line);
char			*sfc_store(char **line);
int				parse_tx(char **line, int j);
int				sfc_tx(char **line, int j);
/*
** checker
*/
int				check_val(void);
int 			check_rows(char *newl);
/*
** checker2
*/
int 			check_updown(char *first, char *last);
int 			check_edges(char **map, int y);// 35 lines
int 			check_line(char **map, int y);
int 			check_map(char **map);

/*
** NEW functions
** parsing
*/
int				ft_parse_line(char *line);
int				ft_check_type(char **line);
int				ft_check_res(char **line);

#endif
