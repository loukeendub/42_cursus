/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:05:20 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/24 11:24:59 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
