/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:12:26 by marvin            #+#    #+#             */
/*   Updated: 2021/03/06 12:16:11 by marvin           ###   ########.fr       */
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
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				c = argv[i][j];
				if (a[c] == 0)
				{
					write(1, &c, 1);
					a[c] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// time		: 10min29sec [home];
// Errors	: 0;
