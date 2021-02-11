/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:01 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/11 12:36:30 by lmarzano         ###   ########.fr       */
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
	char	flags[3];
	int		witdth;
	int		precision;
	char	length[2];
	char	type;
	va_list	args;
}				t_format;
t_format		*g_carrier;
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
/*
** tools [FULL]
*/
void			ft_putchar(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*
** checker [FULL]
*/
void			check_flags(char **c);
void			check_width(char **c);
void			check_precision(char **c);
int				check_length(char **c);
void			check_type(char **c);
#endif
