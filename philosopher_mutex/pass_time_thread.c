/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_time_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:07:06 by junssong          #+#    #+#             */
/*   Updated: 2023/12/10 20:59:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pass_time_thread(t_philo *philo, unsigned long wait_time)
{
	unsigned long	start;
	unsigned long	now;

	start = get_time();
	while (philo->share_t->all_alive)
	{
		now = get_time();
		// printf("%lu\n", now-start);
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
	return (0);
}
