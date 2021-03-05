/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:11:48 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 17:39:32 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char			inventory[256] = {0};
	unsigned char	c;
	int				i;
	int				j;

	if (argc == 3)
	{
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				c = argv[i][j];
				if (!inventory[c])
				{
					write(1, &c, 1);
					inventory[c] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// time	: 7m20s
// error: 1. = line 30 "c = inventory[argv[shelf][item]]"