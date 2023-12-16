/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:23:40 by junssong          #+#    #+#             */
/*   Updated: 2023/12/16 17:25:41 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	destory_all_mutex(t_philo *(philos)[], t_arg *arg, t_share *share);
static void	free_all(t_philo *(philos)[], t_share *share);
static void	print_error(int errn);

int	main(int argc, char *argv[])
{
	int		errn;
	t_arg	arg;
	t_share	share;
	t_philo	*philosopher_array;

	philosopher_array = NULL;
	errn = init_arg(&arg, argc, argv);
	if (errn)
		return (errn);
	errn = init_share_t(&share, &arg);
	if (errn)
		return (errn);
	errn = init_philo(&philosopher_array, &arg, &share);
	if (errn)
		return (errn);
	errn = start_threads(&philosopher_array, &arg);
	destory_all_mutex(&philosopher_array, &arg, &share);
	free_all(&philosopher_array, &share);
	return (errn);
}

void	print_error(int errn)
{
	if (errn == 1)
		printf("Error: number of arguments.\n");
	else if (errn == 2)
		printf("Error: Invalid arguments.\n");
	else if (errn == 3)
		printf("Error: init failed.\n");
}

void	destory_all_mutex(t_philo *(philos)[], t_arg *arg, t_share *share)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philo)
	{
		pthread_mutex_destroy(&((*philos)[i].time_to_eat_mutex));
		pthread_mutex_destroy(&(share->forks_mutexes[i]));
		i++;
	}
	pthread_mutex_destroy(&(share->print_mutex));
	pthread_mutex_destroy(&(share->all_alive_mutex));
	pthread_mutex_destroy(&(share->eat_count_mutex));
}

void	free_all(t_philo *(philos)[], t_share *share)
{
	free(share->forks_sem);
	free(share->forks_array);
	free(*philos);
}
