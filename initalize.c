/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:18:14 by iguney            #+#    #+#             */
/*   Updated: 2025/05/14 17:36:06 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

long	init_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return ((size_t)time.tv_sec * 1000 + (size_t)time.tv_usec / 1000);
}

void	init_threads(void)
{
	
}

void	init_mutex(void)
{
	
}

void	init_philosophers(t_info *info)
{
	int		i;
	t_info *philos;

	i = 0;
	philos = malloc(sizeof(t_info) * info->philo_count);
	while (i++ < info->philo_count)
	{
		philos[i].philo_id = i;
		philos[i].meals_count = info->meals_count;
		philos[i].time_to_starve = info->time_to_starve;
		philos[i].time_to_eat = info->time_to_eat;
		philos[i].time_to_sleep = info->time_to_sleep;
		philos[i].start_time = init_time();
	}
}