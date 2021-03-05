/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:15:13 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 13:40:40 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	inventory[256] = {0};
	int		shelf;
	int		item;
	unsigned char c;

	if (argc == 3)
	{
		shelf = 2;
		while (shelf > 0)
		{
			item = 0;
			while (argv[shelf][item])
			{
				c = argv[shelf][item];
				if (shelf == 2 && !inventory[c])
				{
					inventory[c] = 1;
				}
				else if (shelf == 1 && inventory[c])
				{
					write(1, &argv[c], 1);
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
