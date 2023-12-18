/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:10:06 by junssong          #+#    #+#             */
/*   Updated: 2023/12/18 17:10:07 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	usleep_process(unsigned long wait_time)
{
	unsigned long	start;
	unsigned long	left_time;

	start = get_time();
	left_time = wait_time * 1000;
	while (1)
	{
		if ((get_time() - start) >= wait_time)
			return (0);
		left_time *= 0.25;
		usleep(left_time);
	}
	return (0);
}
