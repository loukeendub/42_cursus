/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:01 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/16 17:08:01 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

/*
** structure
*/
typedef	struct	s_format
{
	int		count;
	int		sign;
	char	flags[3];
	int		wd;
	int		pr;
	char	length[2];
	char	type;
	va_list	args;
}				t_format;
t_format		*g_c;
/*
** ft_printf
*/
int				ft_printf(const char *fstr, ...);
void			print_output(char *fstr);
void			convert_input(char *fstr);
/*
** itoa_conv
*/
int				ft_intcount(int n);
char			*ft_itoa(int n);
int				unsigned_intcount(unsigned int n);
char			*ft_utoa(unsigned int n);
char			*sign_manager(char *s, char *t);
/*
** hex_conv
*/
int				ft_hex_count(int n);
char			*hex_conv(unsigned int n);
char			*ptr_conv(size_t n);
char			*hex_manager(char *s);
/*
** int_flags
*/
char			*d_manager(char *s);
char			*u_manager(char *s);
char			*int_precision(char *s, char *t, size_t len);
char			*prec_manager(char *s, char *t, size_t len);
char			*int_flags(char *s, char *t);
/*
** tools [FULL]
*/
void			ft_putchar(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*
** tools2
*/
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*fill_space(char *s);
/*
** checker [FULL]
*/
void			check_flags(char **c);
void			check_width(char **c);
void			check_precision(char **c);
int				check_length(char **c);
void			check_type(char **c);
#endif
