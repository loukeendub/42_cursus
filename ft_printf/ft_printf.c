/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:18 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/06 16:38:44 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_output(const char *fstr)
{
	int	i;

	while (*fstr)
	{
		if (*fstr != '%')
			ft_putchar(*fstr);
		else
		{
			fstr++;
			check_flags(g_carrier, &fstr);
			check_width(g_carrier, &fstr);
			check_precision(g_carrier, &fstr);
			check_type(g_carrier, &fstr);
		}
		fstr++;
	}
}

int		ft_printf(const char *fstr, ...)
{
	t_format	*carrier;
	t_format	format;

	va_start(format.args, carrier);
	if (!fstr || !*fstr)
		return (-1);
	g_carrier = &carrier;
	g_carrier->count = 0;
	print_output(fstr);
	return (carrier->count);
}
