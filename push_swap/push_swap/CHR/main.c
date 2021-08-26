/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:51:07 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/04 09:49:13 by lmarzano         ###   ########.fr       */
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
		ft_error_finale();
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])) && \
			 argv[i][j] != ' ' && argv[i][j] != '-')
				ft_error_finale();
			j++;
		}
		i++;
	}
	if (!(ft_checkarg(argv, argc)))
		ft_error_finale();
	return (0);
}
