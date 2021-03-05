/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:15:13 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 17:38:57 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	inventory[256] = {0};
	int		i;
	int		j;
	unsigned char c;

	if (argc == 3)
	{
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				c = argv[i][j];
				if (i == 2 && !inventory[c])
					inventory[c] = 1;
				else if (i == 1 && inventory[c] == 1)
				{
					write(1, &c, 1);
					inventory[c] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
