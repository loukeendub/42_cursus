/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:25:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/18 19:01:19 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int		*p;
	int		i;
	//char	*str = "stafava";
	char	c = 'C';

	i = -512;
	p = &i;
	char s[] = "|% -.2c|\n";
	printf(s, c);
	ft_printf(s, c);
	puts("\n--- § ---");
	printf("flags : %c %c %c\n", g_p->flags[0], g_p->flags[1], g_p->flags[2]);
	printf("width : %d\n", g_p->wd);
	printf("precision : %d\n", g_p->pr);
	printf("length : %c%c\n", g_p->length[0], g_p->length[1]);
	printf("type : %c\n", g_p->type);
	printf("sign : %d\n", g_p->sign);
	printf("count : %d\n", g_p->count);
	return (0);
}
/*
** format %[flags][width][.precision][length][type]
*/
