/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 00:56:53 by iguney            #+#    #+#             */
/*   Updated: 2025/06/03 07:38:57 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

int	should_stop(t_info *info)
{
	int	result;

	pthread_mutex_lock(&info->stop_mutex);
	result = info->end_sim;
	pthread_mutex_unlock(&info->stop_mutex);
	return (result);
}

int	check_all_ate(t_info *info)
{
	pthread_mutex_lock(&info->eat_mutex);
	if (info->must_eat_count == -1)
	{
		pthread_mutex_unlock(&info->eat_mutex);
		return (0);
	}
	if (info->all_ate_flag == info->philo_count)
	{
		pthread_mutex_lock(&info->stop_mutex);
		info->end_sim = 1;
		pthread_mutex_unlock(&info->stop_mutex);
		pthread_mutex_unlock(&info->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&info->eat_mutex);
	return (0);
}

int	is_any_dead(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_count)
	{
		pthread_mutex_lock(&info->eat_mutex);
		if ((get_time() - info->philo[i].last_meal_time)
			> info->time_to_starve)
		{
			philo_print(info->philo, i, "is dead");
			pthread_mutex_lock(&info->stop_mutex);
			info->end_sim = 1;
			pthread_mutex_unlock(&info->stop_mutex);
			pthread_mutex_unlock(&info->eat_mutex);
			return (1);
		}
		pthread_mutex_unlock(&info->eat_mutex);
	}
	return (0);
}

void	end_sim(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_count)
		pthread_join(info->thread[i], NULL);
	pthread_join(info->monitor_thread, NULL);
	i = -1;
	while (++i < info->philo_count)
		pthread_mutex_destroy(&info->forks[i]);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->stop_mutex);
	free(info->forks);
	free(info->thread);
	free(info->philo);
}
