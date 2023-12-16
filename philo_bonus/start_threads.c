/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:01:28 by junssong          #+#    #+#             */
/*   Updated: 2023/12/16 18:11:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start_threads(t_philo *(philos)[], t_arg *arg)
{
	pid_t			*child_array;
	int				i;
	unsigned long	now;

	i = 0;
	now = get_time();
	child_array = (pid_t *)malloc(sizeof(pid_t) \
					* (*philos[0]).arg_t->number_of_philo);
	if (child_array == NULL)
		exit(1);
	while (i < arg->number_of_philo)
	{
		sem_wait((*philos[i]).time_to_eat_sem);
		(*philos)[i].time_of_start = now;
		(*philos)[i].time_to_eat = now;
		sem_post((*philos[i]).time_to_eat_sem);
		// 모든 자식이 생성될때까지 기달리게 만들기 (모든포크차지) 그래야 죽는지 확인 가능
		child_array[i] = fork();
		if (child_array[i] == 0)
		{
			if (pthread_create(&((*philos)[i].monitoring_thread), \
				monitor, thread_main, &((*philos)[i])) != 0)
				exit(1);
			thread_main(&((*philos)[i]));
			if (pthread_join((*philos)[i].monitoring_thread, NULL))
				exit(1);
		}
		i++;
	}
	// 생성이 끝나면 포크 풀어주기
	wait_philos(child_array);
}

void	wait_philos(int philo_num, pid_t *child_array)
{
	int	status;
	int	i;

	i = 0;
	waitpid(-1, &status, 0);
	while (i < philo_num)
	{
		kill(child_array[i], SIGKILL);
		i++;
	}
}
