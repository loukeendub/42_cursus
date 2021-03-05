/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:39:10 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 14:53:35 by lmarzano         ###   ########.fr       */
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
		shelf = 2;
		while (shelf > 0)
		{
			item = 0;
			while (argv[shelf][item])
			{
				c = argv[shelf][item];
				if (shelf == 2 && inventory[c] == 0)
					inventory[c] = 1;
				else if (shelf == 1 && inventory[c] == 1)
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

//time	: 8min13sec;
//errors	: 1 = line 25 "while (shelf < 0)"
