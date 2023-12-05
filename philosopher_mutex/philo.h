/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:30:45 by junssong          #+#    #+#             */
/*   Updated: 2023/12/05 18:26:07 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_arg
{
	int		number_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		each_philo_must_eat;
}			t_arg;

typedef struct s_share
{
	pthread_mutex_t	*forks_mutex_array;
	int				*forks_array;
	pthread_mutex_t	all_alive_mutex;
	int				all_alive;
	pthread_mutex_t	print_mutex;
	int				print;
	long			time_of_start;
}			t_share;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	t_arg		*arg_t;
	t_share		*share_t;
	int			eating_count;
	long		time_to_die;
}			t_philo;

int			arg_init(t_arg *arg, int argc, char *argv[]);

// libft
long long	ft_atoi(const char *str);
void		print_error(int errn);
int			philo_init(t_philo *(philo_array)[], t_arg *arg);
void		*do_thread_main(void *arg);

#endif
