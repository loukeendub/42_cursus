/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:26:03 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/15 16:36:15 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_flags(char **c)
{
	while (**c == '-' || **c == '0' || **c == '#' || **c == '+' || **c == ' ')
	{
		if (**c == '-')
			g_c->flags[0] = '-';
		if (**c == '0' && g_c->flags[0] != '-')
			g_c->flags[0] = '0';
		if (**c == '#')
			g_c->flags[1] = '#';
		if (**c == '+')
			g_c->flags[2] = '+';
		if (**c == ' ' && g_c->flags[2] != '+')
			g_c->flags[2] = ' ';
		(*c)++;
	}
}

void	check_width(char **c)
{
	while (**c >= '0' && **c <= '9')
	{
		g_c->width = (g_c->width * 10) + (**c - '0');
		(*c)++;
	}
	if (**c == '*')
		g_c->width = va_arg(g_c->args, int);
}

void	check_precision(char **c)
{
	if (**c == '.')
	{
		g_c->prec = 0;
		(*c)++;
		if (**c >= '0' && **c <= '9')
		{
			while (**c >= '0' && **c <= '9')
			{
				g_c->prec = ((g_c->prec) * 10) + (**c - '0');
				(*c)++;
			}
		}
		else if (**c == '*')
		{
			g_c->prec = va_arg(g_c->args, int);
			(*c)++;
		}
	}
}

int		check_length(char **c)
{
	if (**c == 'l' || **c == 'h')
	{
		if (**c == 'l')
		{
			g_c->length[0] = 'l';
			(*c)++;
			if (**c == 'l')
				g_c->length[1] = 'l';
			else if (**c != 'l' && **c != 'h')
				return (1);
		}
		if (**c == 'h')
		{
			g_c->length[0] = 'h';
			(*c)++;
			if (**c == 'h')
				g_c->length[1] = 'h';
			else if (**c != 'l' && **c != 'h')
				return (1);
		}
		(*c)++;
		return (1);
	}
	return (0);
}

void	check_type(char **c)
{
	if (**c == 'd')
		g_c->type = 'd';
	if (**c == 'i')
		g_c->type = 'i';
	if (**c == 'u')
		g_c->type = 'u';
	if (**c == 'x')
		g_c->type = 'x';
	if (**c == 'X')
		g_c->type = 'X';
	if (**c == 'c')
		g_c->type = 'c';
	if (**c == 's')
		g_c->type = 's';
	if (**c == 'p')
		g_c->type = 'p';
}
