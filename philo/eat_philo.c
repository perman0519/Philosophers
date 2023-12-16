/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:21:00 by junssong          #+#    #+#             */
/*   Updated: 2023/12/16 14:30:47 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_philo(t_philo *philo, t_arg *arg, t_share *share)
{
	pthread_mutex_lock(&(share->forks_mutexes[philo->right_fork]));
	share->forks_array[philo->right_fork] = 1;
	print_thread(philo, share, "has taken a fork");
	if (arg->number_of_philo != 1)
	{
		pthread_mutex_lock(&(share->forks_mutexes[philo->left_fork]));
		share->forks_array[philo->left_fork] = 1;
		print_thread(philo, share, "has taken a fork");
		print_thread(philo, share, "is eating");
		pass_time_thread(share, arg->time_to_eat);
		philo->eating_count++;
		share->forks_array[philo->left_fork] = 0;
		pthread_mutex_unlock(&(share->forks_mutexes[philo->left_fork]));
	}
	else
		pass_time_thread(share, arg->time_to_die);
	share->forks_array[philo->right_fork] = 0;
	pthread_mutex_unlock(&(share->forks_mutexes[philo->right_fork]));
	return (0);
}
