/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:09:18 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/16 17:18:19 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		convert_input(char *fstr)
{
	char	*tmp;

	tmp = 0;
	if (g_c->type == 'c')
		ft_putchar(va_arg(g_c->args, int));
	if (g_c->type == 's')
		ft_putstr(va_arg(g_c->args, char *));
	else
	{
		if (g_c->type == 'd' || g_c->type == 'i')
			tmp = d_manager(tmp);
		if (g_c->type == 'u')
			tmp = u_manager(tmp);
		if (g_c->type == 'x' || g_c->type == 'X')
			tmp = hex_manager(tmp);
		if (g_c->type == 'p')
			tmp = ptr_conv(va_arg(g_c->args, size_t));
		ft_putstr(tmp);
	}
}

static void	init(void)
{
	g_c->flags[0] = 0;
	g_c->flags[1] = '\0';
	g_c->flags[2] = '\0';
	g_c->wd = 0;
	g_c->pr = -1;
	g_c->length[0] = '\0';
	g_c->length[1] = '\0';
	g_c->type = '\0';
	g_c->sign = 0;
}

void		print_output(char *fstr)
{
	while (*fstr)
	{
		if (*fstr != '%' && *fstr != g_c->type)
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
		if (*fstr == g_c->type)
			convert_input(fstr++);
	}
}

int			ft_printf(const char *fstr, ...)
{
	if (!fstr || !*fstr)
		return (-1);
	if (!(g_c = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	va_start(g_c->args, fstr);
	g_c->count = 0;
	print_output((char *)fstr);
	return (g_c->count);
}
