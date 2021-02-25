/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:03:33 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/25 15:21:47 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	standard_order_p(int len)
{
	g_p->wd -= 2;
	while (g_p->wd - g_p->pr > 0)
	{
		ft_putchar(' ');
		g_p->wd--;
	}
	ft_putstr("0x");
	while (g_p->pr - len > 0)
	{
		ft_putchar('0');
		g_p->pr--;
	}
}

void	print_standard_p(char *s, int len)
{
	if (g_p->pr == 0 && s[0] == '0')
	{
		s = "";
		g_p->wd++;
	}
	if (g_p->pr > len)
		standard_order_p(len);
	else
	{
		g_p->wd -= 2;
		while (g_p->wd - len > 0)
		{
			ft_putchar(' ');
			g_p->wd--;
		}
		ft_putstr("0x");
	}
	ft_putstr(s);
}

void	minus_order_p(char *s, int len)
{
	int	prec;

	prec = g_p->pr;
	ft_putstr("0x");
	g_p->wd -= 2;
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

void	print_minus_p(char *s, int len)
{
	if (g_p->pr == 0 && s[0] == '0')
	{
		s = "";
		g_p->wd++;
	}
	if (g_p->pr > len)
		minus_order_p(s, len);
	else
	{
		ft_putstr("0x");
		g_p->wd -= 2;
		ft_putstr(s);
		while (g_p->wd - len > 0)
		{
			ft_putchar(' ');
			g_p->wd--;
		}
	}
}
