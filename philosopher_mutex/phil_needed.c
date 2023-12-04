/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_needed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:39:20 by junssong          #+#    #+#             */
/*   Updated: 2023/12/04 18:46:09 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	value;
	long long	temp;

	sign = 1;
	i = 0;
	value = 0;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		value = 10 * temp + (str[i++] - '0');
		temp = value;
	}
	return (sign * value);
}

void	print_error(int errn)
{
	if (errn == 1)
		printf("Error: number of arguments.\n");
	if (errn == 2)
		printf("Error: Invalid arguments.\n");
}
