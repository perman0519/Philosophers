/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_time_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:07:06 by junssong          #+#    #+#             */
/*   Updated: 2023/12/11 18:52:26 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pass_time_thread(unsigned long wait_time)
{
	unsigned long	start;
	unsigned long	now;
	unsigned long	left_time;

	left_time = wait_time * 1000;
	start = get_time();
	while (1)
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(left_time / 2);
		left_time /= 2;
	}
	return (0);
}
