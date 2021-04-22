/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:57:37 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/22 11:11:05 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int	a;

	a = 16;
	while (a > 0)
	{
		write(1, "na ", 3);
		a--;
		usleep(200000);
	}
	system("clear");
	write(1, "BAT", 3);
	usleep(200000);
	write(1, "MAAAAN", 6);
	return (0);
}