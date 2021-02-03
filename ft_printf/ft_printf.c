/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:18 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/03 18:40:05 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *fstr, ...)
{
	t_format	carrier;

	if (!fstr || !*fstr)
		return (0);
	g_carrier = &carrier;
	g_carrier->count = 0;
	while (*fstr)
	{
		ft_putchar(*fstr);
		fstr++;
	}
	return (g_carrier->count);
}
