/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:01 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/03 18:48:49 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>

/*
** structure
*/
typedef	struct	s_format
{
	int	count;
}				t_format;
t_format		*g_carrier;
/*
** ft_printf
*/
int				ft_printf(const char *fstr, ...);
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
#endif
