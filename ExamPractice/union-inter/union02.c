/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:19:28 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 17:28:19 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned char	c;
	char			inv[256] = {0};
	int				sh;
	int				itm;

	if (argc == 3)
	{
		sh = 1;
		while (sh < 3)
		{
			itm = 0;
			while (argv[sh][itm])
			{
				c = argv[sh][itm];
				if (inv[c] == 0)
				{
					inv[c] = 1;
					write(1, &c, 1);
				}
				itm++;
			}
			sh++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// time		: 6min43sec;
// error	: none!