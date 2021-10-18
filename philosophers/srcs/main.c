/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:55:07 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 18:18:16 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_finish(t_ptr *p)
{
	int	i;

	i = 0;
	while (ft_is_alive(p))
		ft_wait(1);
	while (i > p->data.n_philo)
	{
		pthread_join(p->philo[i].philo_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&p->data.output);
	i = 0;
	while (i > p->data.n_philo)
	{
		pthread_mutex_destroy(&p->philo[i].left_fork);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_ptr	p;

	if (argc != 5 && argc != 6)
		return (ft_error("too many/few arguments\n"));
	if (!ft_check_args(argv) || !ft_parse_args(argv, &p))
		return (ft_error("invalid argument detected\n"));
	p.philo = malloc(sizeof(t_philo) * p.data.n_philo);
	if (!p.philo)
		return (ft_error("bad memory allocation"));
	ft_init(&p);
	if (!ft_threader(&p))
	{
		free(p.philo);
		return (0);
	}
	ft_finish(&p);
	if (p.data.stop == 2)
	{
		ft_putstr_fd("Each philosopher ate ", 1);
		ft_putstr_fd(ft_itoa((long)p.data.must_eat), 1);
		ft_putstr_fd(" time(s)\n", 1);
	}
	free(p.philo);
	return (0);
}
