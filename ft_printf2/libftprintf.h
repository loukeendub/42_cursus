/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:02:53 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/18 15:28:55 by lmarzano         ###   ########.fr       */
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
void			convert_input();
void			print_output(char *format);
int				ft_printf(const char *fstr, ...);
/*
** parse_struct [FULL]
*/
void			parse_flags(char **c);
void			parse_width(char **c);
void			parse_precision(char **c);
int				parse_length(char **c);
/*
** int_manager [FULL]
*/
int				sign_manager(int n);
int				ft_intcount_base(unsigned int n, int base);
char			*ft_utoa(unsigned int n, int base);
void			int_print_flags(char *str);
size_t			set_len(const char *format);
/*
** print_order
*/
void			print_order(char *str);
/*
** utils [FULL]
*/
void			ft_putchar(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

void			convert_d(void);
void			convert_u(void);
void			convert_x(void);
void			convert_p(void);

#endif
