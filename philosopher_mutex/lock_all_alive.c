/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_all_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:58:07 by junssong          #+#    #+#             */
/*   Updated: 2023/12/10 18:04:43 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_all_alive(t_share *share)
{
	int	all_alive;

	pthread_mutex_lock(&(share->all_alive_mutex));
	all_alive = share->all_alive;
	pthread_mutex_unlock(&(share->all_alive_mutex));
	return (all_alive);
}
