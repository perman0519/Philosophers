/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:19:31 by junssong          #+#    #+#             */
/*   Updated: 2023/12/11 16:43:32 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_thread(t_philo *philo, t_share *share, char *msg)
{
	unsigned long	now;

	now = get_time();
	if (now == 0)
		return (-1);
	pthread_mutex_lock(&(share->print_mutex));
	share->print = 1;
	if (is_all_alive(share))
		printf("%lu %d %s\n", now - philo->time_of_start, philo->id, msg);
	share->print = 0;
	pthread_mutex_unlock(&(share->print_mutex));
	return (0);
}
