/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:57:41 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/18 15:30:48 by lmarzano         ###   ########.fr       */
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
	print_order(tmp);
}

void	convert_u(void)
{
	char	*tmp;

	tmp = ft_utoa(va_arg(g_p->args, unsigned int), 10);
	print_order(tmp);
}

void	convert_x(void)
{
	char	*tmp;

	tmp = ft_utoa(va_arg(g_p->args, unsigned int), 16);
	print_order(tmp);
}

void	convert_p(void)
{
	char	*tmp;

	tmp = ft_utoa(va_arg(g_p->args, size_t), 16);
	print_order(tmp);
}