/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:54:44 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 18:54:24 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*
**	[INCLUDES]
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*
**	[DEFINE VARS]
*/
# define TAKE_L_FORK	"picked up the left fork"
# define TAKE_R_FORK	"picked up the right fork"
# define EATING			"is eating"
# define SLEEPING		"is sleeping"
# define THINKING		"is thinking"
# define DEAD			"is dead"
# define ERROR			"Error : "

/*
**	[STRUCTURES]
*/
typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				tot_finish;
	long int		start_time;
	int				stop;
	pthread_mutex_t	output;
	pthread_mutex_t	dead;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	finish;
}					t_data;

typedef struct s_philo
{
	t_data			*pdata;
	int				id;
	long int		eating_time;
	unsigned int	pmust_eat;
	int				finish;
	pthread_t		philo_id;
	pthread_t		death;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
}					t_philo;

typedef struct s_ptr
{
	t_philo			*philo;
	t_data			data;
}					t_ptr;
/*
**	[FUNCTIONS]
*/

/*
**	actions.c
*/
void		ft_take_fork(t_philo *p);
void		ft_eat(t_philo *p);
void		ft_sleep(t_philo *p);
/*
**	thread.c
*/
void		*death_ray(void *data);
void		*routine(void *data);
int			ft_threader(t_ptr *p);
/*
**	thread_utils.c
*/
int			ft_is_alive(t_ptr *p);
int			ft_is_dead(t_philo *p, int i);
void		ft_check_please(t_philo *p);
void		ft_putnbr_fd(int n, int fd);
void		ft_status(t_philo *p, char *status);
/*
**	parsing.c
*/
int			ft_parse_args(char **argv, t_ptr *p);
void		ft_init(t_ptr *p);
/*
**	ft_lib.c
*/
int			ft_strlen(char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(char *str);
/*
**	ft_lib2.c
*/
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_strdup(char *s1);
char		*ft_itoa(long int n);
/*
**	ft_utils.c
*/
long int	ft_time_start(void);
void		ft_wait(long int mstime);
int			ft_isdigit(int c);
int			ft_check_args(char **argv);
int			ft_error(char *str);

#endif
