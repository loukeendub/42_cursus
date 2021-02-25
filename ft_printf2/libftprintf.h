/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:02:53 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/25 14:56:41 by lmarzano         ###   ########.fr       */
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
t_format		*g_p;
/*
** ft_printf
*/
void			convert_input();
int				set_prefix(void);
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
** print_order_cs
*/
void			print_order_s(char *str);
void			convert_c(void);
/*
** order_manager
*/
void			order_manager_d(char *s);
void			order_manager_u(char *s);
void			order_manager_x(char *s);
/*
** print_order_d
*/
void			zero_flag_d(int len);
void			standard_order_d(int len);
void			noprec_order_d(int len);
void			print_standard_d(char *s, int len);
/*
** print_order_minus_d
*/
void			zero_flag_minus_d(int len);
void			standard_order_minus_d(char *s, int len);
void			noprec_order_minus_d(char *s, int len);
void			print_minus_d(char *s, int len);
/*
** print_order_u
*/
void			standard_order_u(int len);
void			print_standard_u(char *s, int len);
void			minus_order_u(int len);
void			print_minus_u(char *s, int len);
/*
** print_order_x
*/
void			standard_order_x(char *s, int len);
void			print_standard_x(char *s, int len);
void			minus_order_x(char *s, int len);
void			print_minus_x(char *s, int len);
/*
** utils [FULL]
*/
void			ft_putchar(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*
** types [FULL]
*/
void			convert_d(void);
void			convert_u(void);
void			convert_x(void);
void			convert_p(void);
void			convert_s(void);

#endif
