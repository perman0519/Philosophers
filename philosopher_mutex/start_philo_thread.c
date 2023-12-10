/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:24:34 by junssong          #+#    #+#             */
/*   Updated: 2023/12/10 20:44:41 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philo_thread(t_philo *(philos)[], t_share *share, t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philo)
	{
		pthread_mutex_lock(&((*philos)[i].time_to_eat_mutex));
		(*philos)[i].time_of_start = get_time();
		(*philos)[i].time_to_eat = get_time();
		pthread_mutex_unlock(&((*philos)[i].time_to_eat_mutex));
		if (pthread_create(&((*philos)[i].thread), \
				NULL, do_thread_main, &((*philos)[i])) != 0)
		{
			return (-1);
		}
		i++;
	}
	i = 0;
	monitor(philos, arg, share);
	while (i < arg->number_of_philo)
	{
		if (pthread_join((*philos)[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}
