/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:40:54 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/01 14:56:36 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	standard_order_x(char *s, int len)
{
	if (g_p->flags[1] == '#' && g_p->pr != 0 && s[0] != '0')
	{
		ft_putstr(g_p->type == 'x' ? "0x" : "0X");
		g_p->wd -= 2;
	}
	while (g_p->wd - g_p->pr > 0)
	{
		ft_putchar(' ');
		g_p->wd--;
	}
	while (g_p->pr - len > 0)
	{
		ft_putchar('0');
		g_p->pr--;
	}
}

void	zero_fill_x(int len)
{
	if (g_p->flags[0] == '0')
		while ((g_p->wd--) - len > 0)
		{
			if (g_p->pr > len || g_p->pr < 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	else
		while (g_p->wd - len > 0)
		{
			ft_putchar(' ');
			g_p->wd--;
		}
}

void	print_standard_x(char *s, int len)
{
	if (g_p->pr == 0 && s[0] == '0')
	{
		s = "";
		g_p->wd++;
	}
	if (g_p->pr > len)
		standard_order_x(s, len);
	else
	{
		if (g_p->flags[1] == '#' && g_p->pr != 0 && s[0] != '0')
		{
			ft_putstr(g_p->type == 'x' ? "0x" : "0X");
			g_p->wd -= 2;
		}
		zero_fill_x(len);
	}
	ft_putstr(s);
}

void	minus_order_x(char *s, int len)
{
	int	prec;

	prec = g_p->pr;
	if (g_p->flags[1] == '#' && s[0] != '0' && s[0] != 0)
	{
		ft_putstr(g_p->type == 'x' ? "0x" : "0X");
		g_p->wd -= 2;
	}
	while (g_p->pr - len > 0)
	{
		ft_putchar('0');
		g_p->pr--;
	}
	ft_putstr(s);
	while (g_p->wd - prec > 0)
	{
		ft_putchar(' ');
		g_p->wd--;
	}
}

void	print_minus_x(char *s, int len)
{
	if (g_p->pr == 0 && s[0] == '0')
	{
		s = "";
		g_p->wd++;
	}
	if (g_p->pr > len)
		minus_order_x(s, len);
	else
	{
		if (g_p->flags[1] == '#' && s[0] != '0' && s[0] != 0)
		{
			ft_putstr(g_p->type == 'x' ? "0x" : "0X");
			g_p->wd -= 2;
		}
		ft_putstr(s);
		while (g_p->wd - len > 0)
		{
			ft_putchar(' ');
			g_p->wd--;
		}
	}
}
