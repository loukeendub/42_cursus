/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:35 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/04 12:49:12 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	while (s3)
	{
		j = 0;
		while (s1)
		{
			s3[i] = s1[j];
			i++;
			j++;
		}
		j = 0;
		while (s1)
		{
			s3[i] = s2[j];
			i++;
			j++;
		}
		s3[i] = '\0';
	}
	return (s3);
}

int		main(int argc, char **argv)
{
	char	*st;
	int		i;
	int		j;
	int		used;

	i = 0;
	used = 0;
	if (argc == 3)
	{
		st = ft_strjoin(argv[1], argv[2]);
		while (st)
		{
			j = 0;
			while (j < i)
			{
				if (st[j] == st[i])
					used = 1;
				j++;
			}
			if (used == 0)
				write(1, &st[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
