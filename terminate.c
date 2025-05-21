/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 00:56:53 by iguney            #+#    #+#             */
/*   Updated: 2025/05/21 07:34:38 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void	destroy_mutex(t_info *info)
{
	int	philo_count;

	philo_count = info->philo_count;
	while (philo_count--)
	{
		pthread_mutex_unlock(&info->forks[philo_count]);
		pthread_mutex_destroy(&info->forks[philo_count]);
	}
	pthread_mutex_unlock(&info->print_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_unlock(&info->stop_mutex);
	pthread_mutex_destroy(&info->stop_mutex);;
}