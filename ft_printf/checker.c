/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:26:03 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/06 16:50:34 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_flags(t_format *carrier, char **c)
{
	while (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ')
	{
		if (c == '-')
			carrier->flags[0] = '-';
		if (c == '0' && carrier->flags[0] != '-')
			carrier->flags[0] = '0';
		if (c == '#')
			carrier->flags[1] = '#';
		if (c == '+')
			carrier->flags[2] = '+';
		if (c == ' ' && carrier->flags[2] != '+')
			carrier->flags[2] = ' ';
		(*c)++;
	}
}

void	check_width(t_format *carrier, char **c)
{
	int	i;

	i = 0;
	while (*c[i] >= '0' && *c[i] <= '9')
	{
		carrier->witdth = (carrier->witdth * 10) + (*c[i] - '0');
		i++;
	}
	if (c == '*')
		carrier->witdth = va_arg(carrier->args, int);
	(*c)++;
}

void	check_precision(t_format *carrier, char **c)
{
	int	i;

	i = 0;
	if (c == '.')
	{
		(*c)++;
		while (c >= '0' && c <= '9')
		{
			carrier->precision = (carrier->precision * 10) + (**c - '0');
			(*c)++;
		}
		if (c == '*')
		{
			carrier->precision = va_arg(carrier->args, int);
			(*c)++;
		}
	}
}

void	check_length(t_format *carrier, char **c)
{
	while (c == 'l' || c == 'h')
	{
		if (c == 'l')
			carrier->length[0] = 'l';
		if ((*c) + 1 == 'l')
			carrier->length[1] = 'l';
		if (c == 'h')
			carrier->length[0] = 'l';
		if ((*c) + 1 == 'h')
			carrier->length[1] = 'l';
	}
	(*c)++;
}

void	check_type(t_format *carrier, char **c)
{
	if (c == 'd')
		carrier->type = 'd';
	if (c == 'i')
		carrier->type = 'i';
	if (c == 'u')
		carrier->type = 'u';
	if (c == 'x')
		carrier->type = 'x';
	if (c == 'X')
		carrier->type = 'X';
	if (c == 'c')
		carrier->type = 'c';
	if (c == 's')
		carrier->type = 's';
	if (c == 'p')
		carrier->type = 'p';
}
