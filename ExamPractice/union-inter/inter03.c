/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:12:14 by marvin            #+#    #+#             */
/*   Updated: 2021/03/06 12:15:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned char	c;
	char			a[256] = {0};
	int				i,j;

	if (argc == 3)
	{
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				c = argv[i][j];
				if (i == 2 && a[c] == 0)
					a[c] = 1;
				else if (i == 1 && a[c] == 1)
				{
					write(1, &c, 1);
					a[c] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n",1);
	return (0);
}

// time		: 8m20s [home];
// errors	: 0;
