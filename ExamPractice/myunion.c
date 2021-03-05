/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:35 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/04 14:57:17 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		used;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			used = 0;
			j = 0;
			while (j < i)
			{
				if (argv[1][j] == argv[1][i])
					used = 1;
				j++;
			}
			if (!used)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			used = 0;
			j = 0;
			while (argv[1][j])
			{
				if (argv[1][j] == argv[2][i])
					used = 1;
				j++;
			}
			j = 0;
			while (j < i)
			{
				if (argv[2][j] == argv[2][i])
					used = 1;
				j++;
			}
			if (!used)
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
