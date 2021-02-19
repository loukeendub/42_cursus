/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:56:26 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/19 18:26:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	order_minus(char *str, int prefix)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	i = print_prefix(prefix);
	len -= i;
	if ((g_p->type == 'x' || g_p->type == 'X') && g_p->flags[1] == '#')
	{
		ft_putstr(g_p->type == 'x' ? "0x" : "0X");
		i++;
	}
	while (i < (g_p->pr == -1 ? g_p->pr - (len) : g_p->pr - len))
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(str);
	if (!(g_p->flags[2] == '#'))
		len++;
	while (i++ <= (g_p->pr == -1 ? g_p->wd - (len) : g_p->wd - (len)))
		ft_putchar(' ');
}

int		print_prefix(int i)
{
	i = 0;
	if (g_p->type == 'p')
	{
		ft_putstr("0x");
		i = 1;
	}
	else if (g_p->sign == 1)
		ft_putchar('-');
	else if (g_p->flags[2] == '+')
	{
		if (!(g_p->type == 'x' || g_p->type == 'X'))
		{
			ft_putchar('+');
			i = 1;
		}
		else
			i = 2;
	}
	else if (g_p->flags[2] == ' ')
		ft_putchar(' ');
	return (i);
}

void	print_order(char *str)
{
	int	i;
	int	len;
	int	prefix;

	i = 0;
	len = ft_strlen(str);
	prefix = set_prefix();
	if (g_p->flags[0] == '-')
		order_minus(str, prefix);
	else
	{
		while (i++ < g_p->wd - (g_p->pr >= 0 ? g_p->pr : 0) - prefix - len)
			ft_putchar(' ');
		i = print_prefix(prefix);
		while (i++ < g_p->pr - len)
			ft_putchar('0');
		if ((g_p->type == 'x' || g_p->type == 'X') && g_p->flags[1] == '#')
		{
			ft_putstr(g_p->type == 'x' ? "0x" : "0X");
			i++;
		}
		ft_putstr(str);
	}
}

void	print_order_s(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	if (g_p->flags[0] == '-')
	{
		ft_putstr(str);
		while (i < g_p->wd - len)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (i < g_p->wd - len)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putstr(str);
	}
}

void	convert_c(void)
{
	char	t;
	int		i;

	t = va_arg(g_p->args, int);
	i = 0;
	if (g_p->flags[0] == '-')
	{
		ft_putchar(t);
		while (i < g_p->wd - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (i < g_p->wd - 1)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar(t);
	}
}
