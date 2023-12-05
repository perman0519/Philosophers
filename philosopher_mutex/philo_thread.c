/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:46 by junssong          #+#    #+#             */
/*   Updated: 2023/12/05 18:26:56 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_thread_main(void *argu)
{
	t_philo	*philo;
	t_arg	*arg;

	philo = (t_philo *)argu;
	arg = philo->arg_t;
	if (philo->id % 2 == 0)
		usleep(1000);
	return (NULL);
}

void	eat_philo()
{

}

void	sleep_philo()
{

}

void	think_philo()
{

}

void	print_thread()
{

}


