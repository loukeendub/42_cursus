/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:25:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/16 11:51:44 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int		*p;
	int		i;

	i = -123;
	p = &i;
	ft_printf("{% d}\n", -123);
	printf("[% d]", i);
	puts("\n--- § ---");
	printf("flags : %c %c %c\n", g_c->flags[0], g_c->flags[1], g_c->flags[2]);
	printf("width : %d\n", g_c->width);
	printf("precision : %d\n", g_c->prec);
	printf("length : %c%c\n", g_c->length[0], g_c->length[1]);
	printf("type : %c\n", g_c->type);
	printf("sign : %d", g_c->sign);
	return (0);
}
/*
** format %[flags][width][.precision][length][type]
*/
