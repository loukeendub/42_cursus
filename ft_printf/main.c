/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:25:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/10 18:05:59 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "stafava";
	ft_printf("ft_ciao  %s  A\n", str);
	//printf("ciao  %c  stafregna", 'A');
	puts("\n--- § ---");
	printf("flags : %c %c %c\n", g_carrier->flags[0], g_carrier->flags[1], g_carrier->flags[2]);
	printf("width : %d\n", g_carrier->witdth);
	printf("precision : %d\n", g_carrier->precision);
	printf("length : %c%c\n", g_carrier->length[0], g_carrier->length[1]);
	printf("type : %c\n", g_carrier->type);
	return (0);
}
/*
** format %[flags][width][.precision][length][type]
*/
