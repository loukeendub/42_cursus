/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:18:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 19:25:21 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_mutex_init(t_ptr *p)
{
	pthread_mutex_init(&p->data.output, NULL);
	pthread_mutex_init(&p->data.dead, NULL);
	pthread_mutex_init(&p->data.is_eating, NULL);
	pthread_mutex_init(&p->data.finish, NULL);
}

static void	ft_link_forks(t_ptr *p, int i)
{
	if (p->data.n_philo == 1)
		p->philo[0].right_fork = &p->philo[0].left_fork;
	else
	{
		if (p->data.n_philo == i + 1)
			p->philo[i].right_fork = &p->philo[0].left_fork;
		else
			p->philo[i].right_fork = &p->philo[i + 1].left_fork;
	}
}

static void	ft_init_philo(t_ptr *p)
{
	int	i;

	i = 0;
	while (p->data.n_philo > i)
	{
		p->philo[i].id = i + 1;
		p->philo[i].pmust_eat = 0;
		p->philo[i].finish = 0;
		p->philo[i].eating_time = p->data.start_time;
		p->philo[i].right_fork = NULL;
		pthread_mutex_init(&p->philo[i].left_fork, NULL);
		ft_link_forks(p, i);
		i++;
	}
}

int	ft_parse_args(char **argv, t_ptr *p)
{
	p->data.n_philo = ft_atoi(argv[1]);
	p->data.t_die = ft_atoi(argv[2]);
	p->data.t_eat = ft_atoi(argv[3]);
	p->data.t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		p->data.must_eat = ft_atoi(argv[5]);
	if (p->data.n_philo <= 0 || p->data.t_die <= 0 \
	|| p->data.t_eat <= 0 || p->data.t_sleep <= 0)
		return (0);
	return (1);
}

void	ft_init(t_ptr *p)
{
	p->data.tot_finish = 0;
	p->data.stop = 0;
	p->data.start_time = ft_time_start();
	ft_mutex_init(p);
	ft_init_philo(p);
}
