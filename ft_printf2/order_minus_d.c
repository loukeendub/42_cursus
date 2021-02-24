/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_minus_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:18:54 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/24 19:41:11 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	zero_flag_minus_d(int len)
{
	if (g_p->flags[2] == '+')
		ft_putchar(g_p->sign == 0 ? '+' : '-');
	else if (g_p->sign == 1)
		ft_putchar('-');
	while ((g_p->wd--) - len > 0)
		ft_putchar('0');
}

void	standard_order_minus_d(char *s, int len)
{
	int	prec;

	prec = g_p->pr;
	if (g_p->sign == 1 || g_p->flags[2] != '\0')
		g_p->wd--;
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
	ft_putstr(s);
	while (g_p->wd - prec > 0)
	{
		ft_putchar(' ');
		g_p->wd--;
	}
}

void	print_minus_d(char *s, int len)
{
	if (g_p->pr == 0 && s[0] == '0')
	{
		s = "";
		g_p->wd++;
	}
	if (g_p->pr > len)
		standard_order_minus_d(s, len);
	else
	{
		if (g_p->sign == 1 || g_p->flags[2] != '\0')
			g_p->wd--;
		if (g_p->flags[0] == '0')
			zero_flag_minus_d(len);
		else
		{
			if (g_p->flags[2] == '+')
				ft_putchar(g_p->sign == 0 ? '+' : '-');
			else if (g_p->sign == 1)
				ft_putchar('-');
			else if (g_p->flags[2] == ' ')
				ft_putchar(' ');
			ft_putstr(s);
			while ((g_p->wd--) - len > 0)
				ft_putchar(' ');
		}
	}
}
