/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:21:00 by junssong          #+#    #+#             */
/*   Updated: 2023/12/05 19:22:46 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, t_arg *arg)
{
	if (philo->id % 2 == 0)
	{
		ptread_mutex_lock(philo->share_t->forks_array[philo->right_fork]);
		philo->share_t->forks_array[philo->right_fork] = 1;
		pthread_mutex_unlock(philo->share_t->forks_array[philo->right_fork]);
		ptread_mutex_lock(philo->share_t->forks_array[philo->left_fork]);
		philo->share_t->forks_array[philo->right_fork] = 1;
		pthread_mutex_unlock(philo->share_t->forks_array[philo->left_fork]);
	}
	else
	{
		ptread_mutex_lock(philo->share_t->forks_array[philo->left_fork]);
		philo->share_t->forks_array[philo->right_fork] = 1;
		pthread_mutex_unlock(philo->share_t->forks_array[philo->left_fork]);
		ptread_mutex_lock(philo->share_t->forks_array[philo->right_fork]);
		philo->share_t->forks_array[philo->right_fork] = 1;
		pthread_mutex_unlock(philo->share_t->forks_array[philo->right_fork]);
	}
}

void	put_fork(t_philo *philo, t_arg *arg)
{
	if (philo->id % 2 == 0)
	{
		ptread_mutex_lock(philo->share_t->forks_array[philo->right_fork]);
		philo->share_t->forks_array[philo->right_fork] = 0;
		pthread_mutex_unlock(philo->share_t->forks_array[philo->right_fork]);
		ptread_mutex_lock(philo->share_t->forks_array[philo->left_fork]);
		philo->share_t->forks_array[philo->right_fork] = 0;
		pthread_mutex_unlock(philo->share_t->forks_array[philo->left_fork]);
	}
	else
	{
		ptread_mutex_lock(philo->share_t->forks_array[philo->left_fork]);
		philo->share_t->forks_array[philo->right_fork] = 0;
		pthread_mutex_unlock(philo->share_t->forks_array[philo->left_fork]);
		ptread_mutex_lock(philo->share_t->forks_array[philo->right_fork]);
		philo->share_t->forks_array[philo->right_fork] = 0;
		pthread_mutex_unlock(philo->share_t->forks_array[philo->right_fork]);
	}
}

void	eat_philo(t_philo *philo, t_arg *arg)
{
	print_thread(philo, arg, FORK);
	print_thread(philo, arg, EAT);
}
