/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:19:00 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 18:26:24 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_is_alive(t_ptr *p)
{
	pthread_mutex_lock(&p->data.dead);
	if (p->data.stop)
	{
		pthread_mutex_unlock(&p->data.dead);
		return (0);
	}
	pthread_mutex_unlock(&p->data.dead);
	return (1);
}

int	ft_is_dead(t_philo *p, int i)
{
	pthread_mutex_lock(&p->pdata->dead);
	if (i)
		p->pdata->stop = i;
	if (p->pdata->stop)
	{
		pthread_mutex_unlock(&p->pdata->dead);
		return (1);
	}
	pthread_mutex_unlock(&p->pdata->dead);
	return (0);
}

void	ft_check_please(t_philo *p)
{
	pthread_mutex_lock(&p->pdata->finish);
	p->finish = 1;
	p->pdata->tot_finish++;
	if (p->pdata->tot_finish == p->pdata->n_philo)
	{
		pthread_mutex_unlock(&p->pdata->finish);
		ft_is_dead(p, 2);
	}
	pthread_mutex_unlock(&p->pdata->finish);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(56, fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd(45, fd);
			ft_putnbr_fd(n * -1, fd);
		}
		else if (n < 10)
			ft_putchar_fd(n + 48, fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + 48, fd);
		}
	}
}

void	ft_status(t_philo *p, char *status)
{
	char	*time;

	time = NULL;
	time = ft_itoa(ft_time_start() - p->pdata->start_time);
	if ((ft_time_start() - p->pdata->start_time) >= 0 && \
	(ft_time_start() - p->pdata->start_time) <= 2147483647 && !ft_is_dead(p, 0))
	{
		ft_putstr_fd(time, 1);
		ft_putstr_fd(" Philosopher ", 1);
		ft_putnbr_fd(p->id, 1);
		ft_putchar_fd(' ', 1);
		ft_putstr_fd(status, 1);
		ft_putchar_fd('\n', 1);
	}
	free (time);
}
