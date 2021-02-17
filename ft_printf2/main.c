/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:25:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/17 17:21:37 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int		*p;
	int		i;

	i = 512;
	p = &i;
	ft_printf("\n{%-8.6d}", 512);
	printf("\n[%-8.6d]\n", i);
	puts("\n--- § ---");
	printf("flags : %c %c %c\n", g_p->flags[0], g_p->flags[1], g_p->flags[2]);
	printf("width : %d\n", g_p->wd);
	printf("precision : %d\n", g_p->pr);
	printf("length : %c%c\n", g_p->length[0], g_p->length[1]);
	printf("type : %c\n", g_p->type);
	printf("sign : %d\n", g_p->sign);
	printf("count : %d\n", g_p->count);
	printf("filler : %d\n\n", g_p->filler);
	return (0);
}
/*
** format %[flags][width][.precision][length][type]
*/
