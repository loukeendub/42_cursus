/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:16:17 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 19:16:09 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_take_fork(t_philo *p)
{
	pthread_mutex_lock(&p->left_fork);
	pthread_mutex_lock(&p->pdata->output);
	ft_status(p, TAKE_L_FORK);
	pthread_mutex_unlock(&p->pdata->output);
	if (!p->right_fork)
	{
		ft_wait(p->pdata->t_die + 10);
		return ;
	}
	pthread_mutex_lock(p->right_fork);
	pthread_mutex_lock(&p->pdata->output);
	ft_status(p, TAKE_R_FORK);
	pthread_mutex_unlock(&p->pdata->output);
}

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(&p->pdata->output);
	ft_status(p, EATING);
	pthread_mutex_lock(&p->pdata->is_eating);
	p->eating_time = ft_time_start();
	pthread_mutex_unlock(&p->pdata->is_eating);
	pthread_mutex_unlock(&p->pdata->output);
	ft_wait(p->pdata->t_eat);
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(&p->left_fork);
}

void	ft_sleep(t_philo *p)
{
	pthread_mutex_lock(&p->pdata->output);
	ft_status(p, SLEEPING);
	pthread_mutex_unlock(&p->pdata->output);
	ft_wait(p->pdata->t_sleep);
}
