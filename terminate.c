/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 00:56:53 by iguney            #+#    #+#             */
/*   Updated: 2025/05/15 01:07:18 by iguney           ###   ########.fr       */
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
	pthread_mutex_unlock(&info->print_lock);
	pthread_mutex_destroy(&info->print_lock);
	pthread_mutex_unlock(&info->lock);
	pthread_mutex_destroy(&info->lock);
}