/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:02:53 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/17 17:12:19 by lmarzano         ###   ########.fr       */
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
	int		filler;
	char	flags[3];
	int		wd;
	int		pr;
	char	length[2];
	char	type;
	va_list	args;
}				t_format;
t_format		*g_p;
/*
** ft_printf
*/
void			parse_struct(char *format_str);
int				ft_printf(const char *fstr, ...);
/*
** parse_struct [FULL]
*/
void			parse_flags(char **c);
void			parse_width(char **c);
void			parse_precision(char **c);
int				parse_length(char **c);
void			parse_type(char **c);
/*
** int_manager
*/
void			int_print_flags(const char *format);
size_t			set_len(const char *format);
/*
** utils
*/
void			ft_putchar(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *s);

#endif
