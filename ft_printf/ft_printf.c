/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:18 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/10 18:12:27 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		convert_input(char *fstr)
{
	if (g_carrier->type == 'c')
		ft_putchar(va_arg(g_carrier->args, int));
	if (g_carrier->type == 's')
		ft_putstr(va_arg(g_carrier->args, char *));
}

static void	init(void)
{
	g_carrier->flags[0] = 0;
	g_carrier->flags[1] = '\0';
	g_carrier->flags[2] = '\0';
	g_carrier->witdth = 0;
	g_carrier->precision = 0;
	g_carrier->length[0] = '\0';
	g_carrier->length[1] = '\0';
	g_carrier->type = '\0';
}

void		print_output(char *fstr)
{
	while (*fstr)
	{
		if (*fstr != '%' && *fstr != g_carrier->type)
		{
			ft_putchar(*fstr);
			fstr++;
		}
		else if (*fstr == '%')
		{
			fstr++;
			init();
			check_flags(&fstr);
			check_width(&fstr);
			check_precision(&fstr);
			check_length(&fstr);
			check_type(&fstr);
		}
		if (*fstr == g_carrier->type)
			convert_input(fstr++);
	}
}

int			ft_printf(const char *fstr, ...)
{
	if (!fstr || !*fstr)
		return (-1);
	if (!(g_carrier = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	va_start(g_carrier->args, fstr);
	g_carrier->count = 0;
	print_output((char *)fstr);
	return (g_carrier->count);
}
