/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:03:04 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/17 18:18:29 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	struct_init(void)
{
	g_p->flags[0] = 0;
	g_p->flags[1] = '\0';
	g_p->flags[2] = '\0';
	g_p->wd = 0;
	g_p->pr = -1;
	g_p->length[0] = '\0';
	g_p->length[1] = '\0';
	g_p->type = '\0';
	g_p->sign = 0;
	g_p->filler = 0;
}

void		convert_input(char *format)
{
	if (g_p->type == 'd' || g_p->type == 'i')
		int_print_flags(format);
	//	if (g_p->type == 'u')
	//	if (g_p->type == 'x' || g_p->type == 'X')
	//	if (g_p->type == 'c')
	//	if (g_p->type == 's')
	//	if (g_p->type == 'p')
}

void		print_output(const char *format)
{
	while (*format)
	{
		if (*format != '%' && *format != g_p->type)
			ft_putchar(*format);
		else if (*format == '%')
		{
			format++;
			struct_init();
			parse_flags(&format);
			parse_width(&format);
			parse_precision(&format);
			parse_length(&format);
			parse_type(&format);
		}
		if (*format == g_p->type)
			convert_input((char *)format);
		format++;
	}
}

int			ft_printf(const char *fstr, ...)
{
	if (!fstr || !*fstr)
		return (-1);
	if (!(g_p = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	va_start(g_p->args, fstr);
	print_output(fstr);
	return (g_p->count);
}
