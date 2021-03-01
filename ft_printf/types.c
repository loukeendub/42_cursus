/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:57:41 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/26 18:48:39 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convert_d(void)
{
	char	*tmp;
	int		n;

	n = va_arg(g_p->args, int);
	if (n < 0)
	{
		n *= -1;
		g_p->sign = 1;
	}
	tmp = ft_utoa(n, 10);
	order_manager_d(tmp);
}

void	convert_u(void)
{
	char	*tmp;

	tmp = ft_utoa(va_arg(g_p->args, unsigned int), 10);
	order_manager_u(tmp);
}

void	convert_x(void)
{
	char	*tmp;

	tmp = ft_utoa(va_arg(g_p->args, unsigned int), 16);
	order_manager_x(tmp);
}

void	convert_p(void)
{
	char	*tmp;

	tmp = ft_sztoa(va_arg(g_p->args, size_t), 16);
	order_manager_p(tmp);
}

void	convert_s(void)
{
	char	*tmp;

	tmp = va_arg(g_p->args, char *);
	print_order_s(tmp);
}
