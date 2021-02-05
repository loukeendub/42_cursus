/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:18 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/05 16:53:48 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_output(const char *fstr)
{
	while (*fstr && *fstr != '%')
	{
		ft_putchar(*fstr);
		fstr++;
	}
	fstr++;
}

int		ft_printf(const char *fstr, ...)
{
	t_format	*carrier;

	if (!fstr || !*fstr)
		return (-1);
	g_carrier = &carrier;
	g_carrier->count = 0;
	print_output(fstr);
	return (carrier->count);
}
