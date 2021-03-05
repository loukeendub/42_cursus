/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:11:48 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 13:39:41 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char			inventory[256] = {0};
	unsigned char	c;
	int				shelf;
	int				item;

	if (argc == 3)
	{
		shelf = 1;
		while (shelf < 3)
		{
			item = 0;
			while (argv[shelf][item])
			{
				c = argv[shelf][item];
				if (!inventory[c])
				{
					write(1, &c, 1);
					inventory[c] = 1;
				}
				item++;
			}
			shelf++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// time	: 7m20s
// error: 1. = line 30 "c = argv[shelf][item]"