/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:10:10 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/26 17:59:05 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	standard_order_u(int len)
{
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

void	print_standard_u(char *s, int len)
{
	if (g_p->pr == 0 && s[0] == '0')
	{
		s = "";
		g_p->wd++;
	}
	if (g_p->pr > len)
		standard_order_u(len);
	else
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
	ft_putstr(s);
}

void	minus_order_u(int len, char *s)
{
	int prec;

	prec = g_p->pr;
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

void	print_minus_u(char *s, int len)
{
	if (g_p->pr == 0 && s[0] == '0')
	{
		s = "";
		g_p->wd++;
	}
	if (g_p->pr > len)
		minus_order_u(len, s);
	else
	{
		ft_putstr(s);
		while (g_p->wd - len > 0)
		{
			ft_putchar(' ');
			g_p->wd--;
		}
	}
}
