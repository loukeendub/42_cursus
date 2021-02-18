/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:15:08 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/18 15:07:00 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parse_flags(char **c)
{
	while (**c == '-' || **c == '0' || **c == '#' || **c == '+' || **c == ' ')
	{
		if (**c == '-')
			g_p->flags[0] = '-';
		if (**c == '0' && g_p->flags[0] != '-')
			g_p->flags[0] = '0';
		if (**c == '#')
			g_p->flags[1] = '#';
		if (**c == '+')
			g_p->flags[2] = '+';
		if (**c == ' ' && g_p->flags[2] != '+')
			g_p->flags[2] = ' ';
		(*c)++;
	}
}

void	parse_width(char **c)
{
	while (**c >= '0' && **c <= '9')
	{
		g_p->wd = (g_p->wd * 10) + (**c - '0');
		(*c)++;
	}
	if (**c == '*')
		g_p->wd = va_arg(g_p->args, int);
}

void	parse_precision(char **c)
{
	if (**c == '.')
	{
		g_p->pr = 0;
		(*c)++;
		if (**c >= '0' && **c <= '9')
		{
			while (**c >= '0' && **c <= '9')
			{
				g_p->pr = ((g_p->pr) * 10) + (**c - '0');
				(*c)++;
			}
		}
		else if (**c == '*')
		{
			g_p->pr = va_arg(g_p->args, int);
			(*c)++;
		}
	}
}

int		parse_length(char **c)
{
	if (**c == 'l' || **c == 'h')
	{
		if (**c == 'l')
		{
			g_p->length[0] = 'l';
			(*c)++;
			if (**c == 'l')
				g_p->length[1] = 'l';
			else if (**c != 'l' && **c != 'h')
				return (1);
		}
		if (**c == 'h')
		{
			g_p->length[0] = 'h';
			(*c)++;
			if (**c == 'h')
				g_p->length[1] = 'h';
			else if (**c != 'l' && **c != 'h')
				return (1);
		}
		(*c)++;
		return (1);
	}
	return (0);
}
