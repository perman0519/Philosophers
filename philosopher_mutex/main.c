/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:23:40 by junssong          #+#    #+#             */
/*   Updated: 2023/12/11 16:06:14 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_mutex_destory(t_philo *(philos)[], t_arg *arg, t_share *share)
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
	free(share->forks_mutexes);
	free(share->forks_array);
	free(share);
	free(*philos);
}

int	main(int argc, char *argv[])
{
	int				errn;
	t_arg			arg_t;
	t_philo			*philosopher_array;

	philosopher_array = NULL;
	errn = arg_init(&arg_t, argc, argv);
	if (errn)
	{
		print_error(errn);
		return (errn);
	}
	errn = philo_init(&philosopher_array, &arg_t);
	if (errn)
	{
		print_error(errn);
		return (errn);
	}
	errn = start_philo_thread(&philosopher_array, &arg_t);
	all_mutex_destory(&philosopher_array, &arg_t, philosopher_array[0].share_t);
	free_all(&philosopher_array, philosopher_array[0].share_t);
	return (errn);
}
