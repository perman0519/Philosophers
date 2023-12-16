/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:24:34 by junssong          #+#    #+#             */
/*   Updated: 2023/12/16 14:54:39 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_philo *(philos)[], t_arg *arg)
{
	int				i;
	unsigned long	now;

	i = 0;
	now = get_time();
	while (i < arg->number_of_philo)
	{
		pthread_mutex_lock(&((*philos)[i].time_to_eat_mutex));
		(*philos)[i].time_of_start = now;
		(*philos)[i].time_to_eat = now;
		pthread_mutex_unlock(&((*philos)[i].time_to_eat_mutex));
		if (pthread_create(&((*philos)[i].thread), \
				NULL, thread_main, &((*philos)[i])) != 0)
			return (-1);
		i++;
	}
	i = 0;
	monitor(philos, arg);
	while (i < arg->number_of_philo)
	{
		if (pthread_join((*philos)[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}
