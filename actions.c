/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:04:56 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/05/21 08:01:51 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void    sleeping(t_philo *philo)
{
    philo_print(philo->info, philo->philo_id, "is sleeping");
    smart_sleep(philo->info->time_to_sleep);
    philo_print(philo->info, philo->philo_id, "is thinking");
}

void    eating(t_philo *philo)
{
    philo_print(philo->info, philo->philo_id, "is eating");
    smart_sleep(philo->info->time_to_eat);
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->meal_mutex);
    philo_print(philo->info, philo->philo_id, "has eaten");
}
void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    philo_print(philo->info, philo->philo_id, "has taken a fork");
    pthread_mutex_lock(philo->right_fork);
    philo_print(philo->info, philo->philo_id, "has taken a fork");
}

void    drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}
