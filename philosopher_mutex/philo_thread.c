/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:46 by junssong          #+#    #+#             */
/*   Updated: 2023/12/12 20:34:29 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_must_eat_count(t_philo *philo, t_arg *arg, t_share *share)
{
	if (philo->eating_count == arg->each_philo_must_eat)
	{
		pthread_mutex_lock(&(share->eat_count_mutex));
		share->eat_count++;
		pthread_mutex_unlock(&(share->eat_count_mutex));
	}
}

void	*do_thread_main(void *argu)
{
	t_philo	*philo;
	t_arg	*arg;
	t_share	*share;
	int		even_odd;

	philo = (t_philo *)argu;
	arg = philo->arg_t;
	share = philo->share_t;
	if (philo->id % 2 != 0)
		usleep(150);
	even_odd = philo->id % 2;
	while (is_all_alive(share))
	{
		eat_philo_even(philo, arg, share);
		if (arg->number_of_philo == 1)
			break ;
		add_must_eat_count(philo, arg, share);
		print_thread(philo, share, "is sleeping");
		pass_time_thread(share, arg->time_to_sleep);
		print_thread(philo, share, "is thinking");
	}
	return (NULL);
}
