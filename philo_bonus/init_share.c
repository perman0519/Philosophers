/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_share.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:12:40 by junssong          #+#    #+#             */
/*   Updated: 2023/12/16 17:22:30 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_t_share_sem(t_share *share, int fork_count);

int	init_share_t(t_share *share, t_arg *arg)
{
	share->forks_array = (int *)malloc(sizeof(int) * arg->number_of_philo);
	if (share->forks_array == NULL)
	{
		print_error(3);
		return (3);
	}
	share->print = 0;
	share->eat_count = 0;
	if (init_t_share_sem(share, arg->number_of_philo) == 1)
	{
		free(share->forks_array);
		free(share->forks_sem);
		print_error(3);
		return (3);
	}
	return (0);
}

static int	init_t_share_sem(t_share *share, int fork_count)
{
	if (sem_unlink("forks_sem") != 0)
		return (1);
	share->forks_sem = sem_open("forks_sem", \
									O_CREAT | O_EXCL, 644, fork_count);
	if (errno != 0)
	{
		free(share->forks_array);
		return (1);
	}
	if (sem_unlink("print_sem") != 0)
		return (1);
	share->print_sem = sem_open("print_sem", O_CREAT | O_EXCL, 0644, 2);
	if (errno != 0)
		return (1);
	if (sem_unlink("eat_count_sem") != 0)
		return (1);
	share->eat_count_sem = sem_open("eat_count_sem", \
										O_CREAT | O_EXCL, 0644, 2);
	if (errno != 0)
	{
		sem_destroy("print_sem");
		return (1);
	}
	return (0);
}
