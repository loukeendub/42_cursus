/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:05:53 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 17:17:43 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char			inventory[256] ={0};
	unsigned char	c;
	int				shelf;
	int				item;

	if (argc == 3)
	{
		shelf = 2;
		while (shelf > 0)
		{
			item = 0;
			while (argv[shelf][item])
			{
				c = argv[shelf][item];
				if (inventory[c] == 0 && shelf == 2)
					inventory[c] = 1;
				else if (inventory[c] == 1 && shelf == 1)
				{
					write(1, &c, 1);
					inventory[c] = 2;
				}
				item++;
			}
			shelf--;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// time		: 8min13sec
// error	: none!