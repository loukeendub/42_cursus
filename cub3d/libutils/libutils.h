/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:55:01 by gscala            #+#    #+#             */
/*   Updated: 2021/04/12 11:38:07 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTILS_H
# define LIBUTILS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define BUFFER_SIZE 1
//# define MAX_OPEN 256

typedef unsigned char	t_uc;
typedef struct s_list
{
	void	*content;
	void	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_get_line_read(int fd, char **remainder);
int				ft_get_next_line(int fd, char **line);

#endif
