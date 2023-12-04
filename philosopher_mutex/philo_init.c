/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:29:58 by junssong          #+#    #+#             */
/*   Updated: 2023/12/04 19:00:05 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_init(t_arg *arg, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (1);
	arg->number_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (arg->number_of_philo <= 0 || arg->time_to_die <= 0 || \
		arg ->time_to_sleep <= 0)
		return (2);
	if (argc == 6)
	{
		arg->each_philo_must_eat = ft_atoi(argv[5]);
		if (arg->each_philo_must_eat <= 0)
			return (2);
	}
	return (0);
}

int	t_share_mutex_init(t_share *t_share, int fork_num)
{
	int	i;

	i = 0;
	while (i < fork_num)
	{
		if (!pthread_mutex_init(&t_share->forks_mutex_array[i], NULL))
			return (1);
		i++;
	}
	if (!pthread_mutex_init(&t_share->print_mutex, NULL))
		return (1);
}

t_share	*make_share_t(t_arg *arg)
{
	t_share			t_share;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (NULL);
	t_share.time_of_start = tv.tv_usec;
	t_share.forks_array = (int *)malloc(sizeof(int) * arg->number_of_philo);
	if (t_share.forks_array == NULL)
		return (NULL);
	t_share.forks_mutex_array = (pthread_mutex_t *) \
				malloc(sizeof(pthread_mutex_t) * arg->number_of_philo);
	if (t_share.forks_mutex_array == NULL)
	{
		free(t_share.forks_array);
		return (NULL);
	}
	t_share.print = 0;

	return (&t_share);
}

t_philo	*make_philo_t(t_arg *arg, int philo_num)
{
	t_philo	philo_t;

	philo_t.number = philo_num;
	pthread_create(&philo_t.thread, NULL, NULL, NULL);
	philo_t.time_to_die = 0;
	philo_t.eating_count = 0;
	philo_t.arg_t = arg;
//    t_philo.t_share =
}

int	philo_init(t_philo *philo_array, t_arg *arg)
{
	int	i;

	i = 0;
	philo_array = (t_philo *)malloc(sizeof(t_philo) * \
							arg->number_of_philo);
	if (philo_array == NULL)
		return (1);
	while (i < arg->number_of_philo)
	{
		philo_array[i] = *make_philo_t(arg, i);
		i++;
	}
}
