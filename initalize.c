/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:18:14 by iguney            #+#    #+#             */
/*   Updated: 2025/05/29 18:57:21 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void	init_mutex(t_info *info)
{
	int	i;

	i = -1;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_count);
	while (++i < info->philo_count)
		pthread_mutex_init(&info->forks[i], NULL);
	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->stop_mutex, NULL);
}

void	init_philosophers(t_info *info)
{
	int		i;

	i = -1;
	info->philo = malloc(sizeof(t_philo) * info->philo_count);
	if (info->philo == NULL)
		return (free(info->forks));
	while (++i < info->philo_count)
	{
		info->philo[i].id = i;
		info->philo[i].meals_eaten = 0;
		info->philo[i].is_alive = 1;
		info->philo[i].last_meal_time = get_time();
		info->philo[i].left_fork = &info->forks[i];
		info->philo[i].right_fork = &info->forks[(i + 1) % info->philo_count];
		info->philo[i].info = info;
	}
}

void	init_threads(t_info *info)
{
	int i;
	pthread_t		*thread;

	i = -1;
	thread = malloc(sizeof(pthread_t) * info->philo_count);
	info->start_time = get_time();
	while (++i < info->philo_count)
		pthread_create(&thread[i], NULL, philo_routine, (void *)&info->philo[i]);
	// pthread_create(&info->monitor_thread, NULL, monitor, NULL);
	i = -1;
	while (++i < info->philo_count)
		pthread_join(thread[i], NULL);
	// pthread_join(info->monitor_thread, NULL);
}
