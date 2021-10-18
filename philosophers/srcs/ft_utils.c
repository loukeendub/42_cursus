/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:17:14 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 18:24:53 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_time_start(void)
{
	long int		start;
	struct timeval	current_t;

	start = 0;
	gettimeofday(&current_t, NULL);
	start = (current_t.tv_sec * 1000) + (current_t.tv_usec / 1000);
	return (start);
}

void	ft_wait(long int mstime)
{
	long int	start;

	start = 0;
	start = ft_time_start();
	while ((ft_time_start() - start) < mstime)
		usleep(mstime / 10);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_check_args(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || ft_strlen(argv[i]) > 10)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_error(char *str)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(str, 2);
	return (0);
}
