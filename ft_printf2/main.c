/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:25:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/26 18:16:37 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int		i;

	i = 15;
	int		*a01 = &i;
	int		*a02 = &i;
	int		*a03 = &i;
	int		*a04 = &i;
	int		*a05 = &i;
	int		*a06 = &i;
	int		*a07 = &i;
	int		*a08 = &i;
	int		*a09 = &i;
	int		*a10 = &i;
	int		*a11 = &i;
	int		*a12 = &i;
	int		res1;
	//char	*str = "hello, world!";
	//char	c = 'C';

	//*p = &i;
	//char s[] = "|%015u|\n";
	res1 = printf("*|%p%p%p%p%p%p%p%p%p%p%p%p|\n", &a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("#|%p%p%p%p%p%p%p%p%p%p%p%p|\n", &a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
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
