/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:26:03 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/09 15:22:12 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_flags(char **c)
{
	while (**c == '-' || **c == '0' || **c == '#' || **c == '+' || **c == ' ')
	{
		if (**c == '-')
			g_carrier->flags[0] = '-';
		if (**c == '0' && g_carrier->flags[0] != '-')
			g_carrier->flags[0] = '0';
		if (**c == '#')
			g_carrier->flags[1] = '#';
		if (**c == '+')
			g_carrier->flags[2] = '+';
		if (**c == ' ' && g_carrier->flags[2] != '+')
			g_carrier->flags[2] = ' ';
		(*c)++;
	}
}

void	check_width(char **c)
{
	while (**c >= '0' && **c <= '9')
	{
		g_carrier->witdth = (g_carrier->witdth * 10) + (**c - '0');
		(*c)++;
	}
	if (**c == '*')
		g_carrier->witdth = va_arg(g_carrier->args, int);
}

void	check_precision(char **c)
{
	if (**c == '.')
	{
		(*c)++;
		while (**c >= '0' && **c <= '9')
		{
			g_carrier->precision = (g_carrier->precision * 10) + (**c - '0');
			(*c)++;
		}
		if (**c == '*')
			g_carrier->precision = va_arg(g_carrier->args, int);
	}
}

void	check_length(char **c)
{
	if (**c == 'l' || **c == 'h')
	{
		if (**c == 'l')
		{
			g_carrier->length[0] = 'l';
			(*c)++;
			if (**c == 'l')
				g_carrier->length[1] = 'l';
		}
		if (**c == 'h')
		{
			g_carrier->length[0] = 'h';
			(*c)++;
			if (**c == 'h')
				g_carrier->length[1] = 'h';
		}
	}
	(*c)++;
}

void	check_type(char **c)
{
	if (**c == 'd')
		g_carrier->type = 'd';
	if (**c == 'i')
		g_carrier->type = 'i';
	if (**c == 'u')
		g_carrier->type = 'u';
	if (**c == 'x')
		g_carrier->type = 'x';
	if (**c == 'X')
		g_carrier->type = 'X';
	if (**c == 'c')
		g_carrier->type = 'c';
	if (**c == 's')
		g_carrier->type = 's';
	if (**c == 'p')
		g_carrier->type = 'p';
}
