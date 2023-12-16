/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_time_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:07:06 by junssong          #+#    #+#             */
/*   Updated: 2023/12/16 14:52:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	usleep_thread(t_share *share, unsigned long wait_time)
{
	unsigned long	start;
	unsigned long	left_time;

	start = get_time();
	left_time = wait_time * 1000;
	while (1)
	{
		if ((get_time() - start) >= wait_time || !is_all_alive(share))
			return (0);
		left_time *= 0.25;
		usleep(left_time);
	}
	return (0);
}
