/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:28:38 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/17 17:36:59 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	int_print_flags(const char *format)
{
	int	dif;

	while (*format++ == g_p->type)
	{
		if (g_p->flags[2] == '+')
			ft_putchar(g_p->sign == 0 ? '+' : '-');
		else if (g_p->flags[2] == ' ')
			ft_putchar(' ');
		if (g_p->flags[0] == '-')
		{
			dif = g_p->wd > g_p->pr ? g_p->wd - g_p->pr : g_p->pr - g_p->wd;
			while (dif-- != -1)
				ft_putchar('0');
		}
	}
}

size_t	set_len(const char *format)
{
	size_t	size;

	if (g_p->wd > g_p->pr || g_p->wd > ft_strlen(format))
	{
		size = g_p->wd;
		g_p->filler = 1; //filler prints spaces
	}
	if (g_p->wd < g_p->pr && g_p->pr > ft_strlen(format))
	{
		size = g_p->pr;
		g_p->filler = 0; //filler prints zeroes
	}
	if (g_p->wd < g_p->pr && g_p->pr < ft_strlen(format))
		size = ft_strlen(format);
	return (size);
}
