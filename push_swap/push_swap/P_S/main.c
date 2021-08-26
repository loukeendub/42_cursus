/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:51:07 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/04 10:12:46 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		ft_error_finalep();
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])) && \
			 argv[i][j] != ' ' && argv[i][j] != '-')
				ft_error_finalep();
			j++;
		}
		i++;
	}
	if (!(ft_checkargp(argv, argc)))
		ft_error_finalep();
	return (0);
}
