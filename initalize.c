/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:18:14 by iguney            #+#    #+#             */
/*   Updated: 2025/05/21 08:08:09 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return ((size_t)time.tv_sec * 1000 + (size_t)time.tv_usec / 1000);
}

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
	t_philo *philos;

	i = -1;
	philos = malloc(sizeof(t_philo) * info->philo_count);
	while (++i < info->philo_count)
	{
		philos[i].philo_id = i;
		philos[i].info = info;
		philos[i].info->time_to_starve = info->time_to_starve;
		philos[i].info->must_eat_count = info->must_eat_count;
		philos[i].info->time_to_eat = info->time_to_eat;
		philos[i].info->time_to_sleep = info->time_to_sleep;
		philos[i].info->end_sim = 0;
		philos[i].info->start_time = get_time();
		philos[i].left_fork = &info->forks[i];
		philos[i].right_fork = &info->forks[(i + 1) % info->philo_count];
		philos[i].is_alive = 1;
	}
}

void	init_threads(t_info *info)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = info->philo;
	while (++i < info->philo_count)
	{
		pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
		pthread_join(philos[i].thread, NULL);
	}
	pthread_create(&info->philo->thread, NULL, monitor, info);
	pthread_join(info->philo->thread, NULL);
}
void	smart_sleep(size_t wait_time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < wait_time)
		usleep(500);
}
