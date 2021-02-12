/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:25:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/12 18:49:05 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	*p;
	int		i;

	i = 123;
	p = &i;
	ft_printf("{%-8d}\n", 123);
	printf("[%-8d]", i);
	//printf("ciao  %p  A\n", p);
	puts("\n--- § ---");
	printf("flags : %c %c %c\n", g_c->flags[0], g_c->flags[1], g_c->flags[2]);
	printf("width : %d\n", g_c->width);
	printf("precision : %d\n", g_c->precision);
	printf("length : %c%c\n", g_c->length[0], g_c->length[1]);
	printf("type : %c\n", g_c->type);
	return (0);
}
/*
** format %[flags][width][.precision][length][type]
*/
