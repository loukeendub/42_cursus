/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:01 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/06 15:06:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
** structure
*/
typedef	struct	s_format
{
	int		count;
	char	flags[3];
	int		witdth;
	int		precision;
	int		length[2];
	char	type;
	va_list	args;
}				t_format;
t_format		*g_carrier;
/*
** ft_printf
*/
int				ft_printf(const char *fstr, ...);
void			print_output(const char *fstr);
/*
** converter
*/
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
/*
** tools
*/
void			ft_putchar(int c);
size_t			ft_strlen(const char *s);
/*
** checker
*/
void			check_flags(t_format *carrier, char **c);
void			check_width(t_format *carrier, char **c);
void			check_precision(t_format *carrier, char **c);
void			check_length(t_format *carrier, char **c);
void			check_type(t_format *carrier, char **c);
#endif
