/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:56:26 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/18 17:49:19 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_prefix(int i)
{
	if (g_p->type == 'p')
	{
		ft_putstr("0x");
		i = 1;
	}
	else if (g_p->sign == 1)
	{
		ft_putchar('-');
		i = 0;
	}
	else if (g_p->flags[2] == '+')
	{
		ft_putchar('+');
		i = 0;
	}
	else if (g_p->flags[2] == ' ')
	{
		ft_putchar(' ');
		i = 0;
	}
	return (i);
}

void	print_order(char *str)
{
	int	i;
	int	len;
	int	prefix;

	i = 0;
	len = ft_strlen(str);
	prefix = (g_p->type == 'p') * 2 || g_p->sign || g_p->flags[2] == '+' || g_p->flags[2] == ' ';
	if (g_p->flags[0] == '-')
	{
		i = print_prefix(prefix);
		while (i++ < g_p->pr - len)
			ft_putchar('0');
		ft_putstr(str);
		while (i++ < g_p->wd - len - prefix)
			ft_putchar(' ');
		printf("[%d]", prefix);
	}
	else
	{
		while (i++ < g_p->wd - g_p->pr - 1)
			ft_putchar(' ');
		i = print_prefix(prefix);
		while (i++ < g_p->pr - len)
			ft_putchar('0');
		ft_putstr(str);
	}
}
