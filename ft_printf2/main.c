/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:25:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/26 17:38:26 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int		*p;
	int		i;
	int		res1;
	//char	*str = "hello, world!";
	//char	c = 'C';

	i = 15;
	p = &i;
	//char s[] = "|%015u|\n";
	res1 = printf("*|%-8.5u|\n", 34);
	ft_printf("#|%-8.5u|\n", 34);
	puts("\n--- § ---");
	printf("flags : %c %c %c\n", g_p->flags[0], g_p->flags[1], g_p->flags[2]);
	printf("width : %d\n", g_p->wd);
	printf("precision : %d\n", g_p->pr);
	printf("length : %c%c\n", g_p->length[0], g_p->length[1]);
	printf("type : %c\n", g_p->type);
	printf("sign : %d\n", g_p->sign);
	printf("count : %d\n", g_p->count);
	printf("printf count : %d\n", res1);
	return (0);
}
/*
** format %[flags][width][.precision][length][type]
*/
