/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:46 by junssong          #+#    #+#             */
/*   Updated: 2023/12/11 17:44:40 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_must_eat_count(t_philo *philo, t_arg *arg, t_share *share)
{
	if (philo->eating_count == arg->each_philo_must_eat)
	{
		pthread_mutex_lock(&(share->eat_count_mutex));
		share->eat_count += 1;
		pthread_mutex_unlock(&(share->eat_count_mutex));
	}
}

void	*do_thread_main(void *argu)
{
	t_philo	*philo;
	t_arg	*arg;
	t_share	*share;

	philo = (t_philo *)argu;
	arg = philo->arg_t;
	share = philo->share_t;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (is_all_alive(share))
	{
		if (philo->id % 2 == 0)
			eat_philo_even(philo, arg, share);
		else
			eat_philo_odd(philo, arg, share);
		add_must_eat_count(philo, arg, share);
		print_thread(philo, share, "is sleeping");
		pass_time_thread(arg->time_to_sleep);
		print_thread(philo, share, "is thinking");
	}
	return (NULL);
}
