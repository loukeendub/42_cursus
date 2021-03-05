/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:17:00 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 12:31:34 by lmarzano         ###   ########.fr       */
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
					inventory[c] = 1;
					write(1, &c, 1);
				}
				item++;
			}
			shelf++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
