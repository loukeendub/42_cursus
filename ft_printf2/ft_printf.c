/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:03:04 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/25 12:14:09 by lmarzano         ###   ########.fr       */
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
}

void		convert_input(void)
{
	char	*tmp;

	tmp = 0;
	if (g_p->type == 'd' || g_p->type == 'i')
		convert_d();
	else if (g_p->type == 'u')
		convert_u();
	else if (g_p->type == 'x' || g_p->type == 'X')
		convert_x();
	else if (g_p->type == 'c')
		convert_c();
	else if (g_p->type == 's')
		convert_s();
	else if (g_p->type == 'p')
		convert_p();
}

int			set_prefix(void)
{
	if (g_p->type == 'p')
		return (2);
	else if ((g_p->type == 'X' || g_p->type == 'x') && g_p->flags[1] == '#')
		return (2);
	else if (g_p->sign || g_p->flags[2] == '+' || g_p->flags[2] == ' ')
		return (1);
	return (0);
}

void		print_output(char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			struct_init();
			parse_flags(&format);
			parse_width(&format);
			parse_precision(&format);
			parse_length(&format);
			g_p->type = *format;
			convert_input();
		}
		else
			ft_putchar(*format);
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
	print_output((char *)fstr);
	va_end(g_p->args);
	return (g_p->count);
}
