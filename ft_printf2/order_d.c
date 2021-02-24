/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:20:00 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/24 19:39:31 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	zero_flag_d(int len)
{
	if (g_p->flags[2] == '+')
		ft_putchar(g_p->sign == 0 ? '+' : '-');
	else if (g_p->sign == 1)
		ft_putchar('-');
	while ((g_p->wd--) - len > 0)
		ft_putchar('0');
}

void	standard_order_d(int len)
{
	if (g_p->sign == 1 || g_p->flags[2] != '\0')
		g_p->wd--;
	while (g_p->wd - g_p->pr > 0)
	{
		ft_putchar(' ');
		g_p->wd--;
	}
	if (g_p->flags[2] == '+')
		ft_putchar(g_p->sign == 0 ? '+' : '-');
	else if (g_p->sign == 1)
		ft_putchar('-');
	else if (g_p->flags[2] == ' ')
		ft_putchar(' ');
	while (g_p->pr - len > 0)
	{
		ft_putchar('0');
		g_p->pr--;
	}
}

void	print_standard_d(char *s, int len)
{
	if (g_p->pr == 0 && s[0] == '0')
	{
		s = "";
		g_p->wd++;
	}
	if (g_p->pr > len)
		standard_order_d(len);
	else
	{
		if (g_p->sign == 1 || g_p->flags[2] != '\0')
			g_p->wd--;
		if (g_p->flags[0] == '0')
			zero_flag_d(len);
		else
		{
			while ((g_p->wd--) - len > 0)
				ft_putchar(' ');
			if (g_p->flags[2] == '+')
				ft_putchar(g_p->sign == 0 ? '+' : '-');
			else if (g_p->sign == 1)
				ft_putchar('-');
			else if (g_p->flags[2] == ' ')
				ft_putchar(' ');
		}
	}
	ft_putstr(s);
}
