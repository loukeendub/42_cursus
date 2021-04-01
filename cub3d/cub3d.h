/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/01 10:25:16 by lmarzano         ###   ########.fr       */
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
}				t_check;

typedef struct	s_all
{
	t_parse	*par;
	t_check	*chr;
}				t_all;

/*
** init [FULL]
*/
void			ft_str_all_init(t_all *all);
void			ft_struct_init(t_all *all);
void			ft_tx_init(t_all *all);
void			ft_ref_init(t_all *all);
void			ft_check_init(t_all *all);
/*
** parsing 
*/
int				ft_parse_line(char *line, int fd, t_all *all);
int				ft_check_walls(char **line, t_all *all);
int				ft_check_type(char **line, t_all *all);
char			*ft_text_store(char **line);
/*
** parsing2
*/
int				ft_parse_digit(char **line, t_all *all);
int				ft_parse_digit2(char **line, t_all *all);
/*
** map_parsing 
*/
int				ft_map_parse(char **line, int fd, t_all *all);
int				ft_check_rows(char *newl, t_all *all);
int				ft_check_map(char **map, t_all *all);
int				ft_check_updown(char *first, char *last, t_all *all);
/*
** map_parsing2
*/
int				ft_check_line(char **map, int y, t_all *all);
int				ft_check_edges(char **map, int y);
int				ft_check_previous(char **map, int y, int x, int previous);
int				ft_check_current(char **map, int y, int x, int current);
/*
** GNL
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
int				ft_split_core(char *s, char **arr, char c, t_all *all);
char			**ft_split(char *s, char c, t_all *all);
/*
** utils_3
*/
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
int				ft_itoa(char **line, t_all *all, int h);
int				ft_itoa2(char **line, t_all *all, int h);
int				ft_itoa3(char **line, t_all *all, int h);

#endif
