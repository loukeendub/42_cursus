/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:06:19 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/10 12:54:15 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
int	main(void)
{
	char	c = 'a';

	read(1,&c,1);
	printf("err: %d\n", errno);
	errno = 0;
	ft_read(1,&c,1);
	printf("err: %d\n", errno);

	return (0);
}