/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:19:20 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 18:59:13 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*death_ray(void *data)
{
	t_philo	*p;

	p = data;
	ft_wait(p->pdata->t_die + 1);
	pthread_mutex_lock(&p->pdata->is_eating);
	pthread_mutex_lock(&p->pdata->finish);
	if (!ft_is_dead(p, 0) && !p->finish && \
	((ft_time_start() - p->eating_time) >= (long)p->pdata->t_die))
	{
		pthread_mutex_unlock(&p->pdata->is_eating);
		pthread_mutex_unlock(&p->pdata->finish);
		pthread_mutex_lock(&p->pdata->output);
		ft_status(p, DEAD);
		pthread_mutex_unlock(&p->pdata->output);
		ft_is_dead(p, 1);
	}
	pthread_mutex_unlock(&p->pdata->is_eating);
	pthread_mutex_unlock(&p->pdata->finish);
	return (NULL);
}

void	*routine(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	if (p->id % 2 == 0)
		ft_wait(p->pdata->t_eat / 10);
	while (!ft_is_dead(p, 0))
	{
		pthread_detach(p->death);
		pthread_create(&p->death, NULL, death_ray, data);
		ft_take_fork(p);
		ft_eat(p);
		ft_sleep(p);
		pthread_mutex_lock(&p->pdata->output);
		ft_status(p, THINKING);
		pthread_mutex_unlock(&p->pdata->output);
		if ((int)++p->pmust_eat == p->pdata->must_eat)
		{
			ft_check_please(p);
			return (NULL);
		}
	}
	pthread_detach(p->death);
	return (NULL);
}

int	ft_threader(t_ptr *p)
{
	int	i;

	i = 0;
	while (i < p->data.n_philo)
	{
		p->philo[i].pdata = &p->data;
		if (pthread_create(&p->philo[i].philo_id, NULL, routine, &p->philo[i]))
			return (ft_error("thread task unsuccesful\n"));
		i++;
	}
	return (1);
}
