/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:29:58 by junssong          #+#    #+#             */
/*   Updated: 2023/12/05 18:54:08 by junssong         ###   ########.fr       */
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

int	t_share_mutex_init(t_share *t_share, int fork_count)
{
	int	i;

	i = 0;
	while (i < fork_count)
	{
		if (!pthread_mutex_init(&t_share->forks_mutex_array[i], NULL))
			return (1);
		i++;
	}
	if (!pthread_mutex_init(&t_share->print_mutex, NULL))
		return (1);
	return (0);
}

int	make_share_t(t_share *share_t, t_arg *arg)
{
	struct timeval	tv;

	if (share_t == NULL)
		return (1);
	if (gettimeofday(&tv, NULL) != 0)
		return (1);
	share_t->time_of_start = tv.tv_usec;
	share_t->forks_array = (int *)malloc(sizeof(int) * arg->number_of_philo);
	share_t->forks_mutex_array = (pthread_mutex_t *) \
				malloc(sizeof(pthread_mutex_t) * arg->number_of_philo);
	if (share_t->forks_array == NULL)
	{
		free(share_t);
		return (1);
	}
	if (share_t->forks_mutex_array == NULL)
	{
		free(share_t);
		free(share_t->forks_array);
		return (1);
	}
	share_t->print = 0;
	t_share_mutex_init(share_t, arg->number_of_philo);
	return (0);
}

t_philo	*make_philo_t(t_philo *philo_t, t_arg *arg, \
						t_share *share_t, int philo_num)
{
	philo_t->id = philo_num;
	pthread_create(&(philo_t->thread), NULL, do_thread_main, (void *)philo_t);
	philo_t->time_to_die = 0;
	philo_t->eating_count = 0;
	philo_t->arg_t = arg;
	philo_t->left_fork = philo_num;
	philo_t->right_fork = (philo_num + 1) % arg->number_of_philo;
	philo_t->share_t = share_t;
	return (philo_t);
}

int	philo_init(t_philo *(philo_array)[], t_arg *arg)
{
	t_share	*share_t;
	int		i;

	i = 0;
	share_t = (t_share *)malloc(sizeof(t_share));
	if (make_share_t(share_t, arg))
		return (1);
	*philo_array = (t_philo *)malloc(sizeof(t_philo) * \
							arg->number_of_philo);
	if (philo_array == NULL)
	{
		free(share_t);
		return (1);
	}
	while (i < arg->number_of_philo)
	{
		make_philo_t(&((*philo_array)[i]), arg, share_t, i);
		printf("philo init %d\n", (*philo_array)[i].id);
		i++;
	}
	return (0);
}
