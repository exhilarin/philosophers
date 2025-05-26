/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:04:56 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/05/26 21:22:24 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void    take_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->right_fork);
        philo_print(philo, philo->id, "has taken a fork");
        pthread_mutex_lock(philo->left_fork);
        philo_print(philo, philo->id, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        philo_print(philo, philo->id, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        philo_print(philo, philo->id, "has taken a fork");
    }
}
void    eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time = get_time();
    philo_print(philo, philo->id, "is eating");
    smart_sleep(philo->info->time_to_eat);
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_mutex);
    if ((philo->info->must_eat_count != -1) && philo->meals_eaten == philo->info->must_eat_count)
        philo->info->all_ate_flag++;
}

void    drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void    sleeping(t_philo *philo)
{
    philo_print(philo, philo->id, "is sleeping");
    smart_sleep(philo->info->time_to_sleep);
    philo_print(philo, philo->id, "is thinking");
}
