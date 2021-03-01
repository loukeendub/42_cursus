/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order_cs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:05:20 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/26 16:46:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	prec_manager_s(char *str, int prec)
{
	int	len;

	len = ft_strlen(str);
	if (prec < 0)
		ft_putstr(str);
	else
		while ((len - prec > 0 ? prec-- : len--) > 0)
		{
			ft_putchar(*str);
			str++;
		}
}

void	wd_manager_s(int i, int len, int prec)
{
	if (prec < 0)
	{
		while (i < g_p->wd - len)
		{
			ft_putchar(g_p->flags[0] == '0' ? '0' : ' ');
			i++;
		}
	}
	else
	{
		while (i < g_p->wd - (prec > len ? len : prec))
		{
			ft_putchar(' ');
			i++;
		}
	}
}

void	print_order_s(char *str)
{
	int	len;
	int	i;
	int	prec;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	prec = g_p->pr;
	if (g_p->flags[0] == '-')
	{
		prec_manager_s(str, prec);
		wd_manager_s(i, len, prec);
	}
	else
	{
		wd_manager_s(i, len, prec);
		prec_manager_s(str, prec);
	}
}

void	print_order_c(char t)
{
	int	i;

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
			ft_putchar(g_p->flags[0] == '0' ? '0' : ' ');
			i++;
		}
		ft_putchar(t);
	}
}

void	convert_c(void)
{
	char	t;

	if (g_p->type == '%')
		t = '%';
	else
		t = va_arg(g_p->args, int);
	print_order_c(t);
}
