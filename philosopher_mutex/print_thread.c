/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:19:31 by junssong          #+#    #+#             */
/*   Updated: 2023/12/12 16:08:46 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_thread(t_philo *philo, t_share *share, char *msg)
{
	unsigned long	now;

	pthread_mutex_lock(&(share->all_alive_mutex));
	now = get_time();
	if (now == 0)
		return (-1);
	share->print = 1;
	if (share->all_alive)
		printf("%lu %d %s\n", now - philo->time_of_start, philo->id, msg);
	share->print = 0;
	pthread_mutex_unlock(&(share->all_alive_mutex));
	return (0);
}
