/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:04:56 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/05/23 23:53:10 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void    take_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->left_fork);
        philo_print(philo->info, philo->id, "has taken left fork");
        pthread_mutex_lock(philo->right_fork);
        philo_print(philo->info, philo->id, "has taken right fork");
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        philo_print(philo->info, philo->id, "has taken right fork");
        pthread_mutex_lock(philo->left_fork);
        philo_print(philo->info, philo->id, "has taken left fork");
    }
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time = get_time();
    philo_print(philo->info, philo->id, "is eating");
    smart_sleep(philo->info->time_to_eat);
    pthread_mutex_unlock(&philo->meal_mutex);
}

void    drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void    sleeping(t_philo *philo)
{
    philo_print(philo->info, philo->id, "is sleeping");
    smart_sleep(philo->info->time_to_sleep);
    philo_print(philo->info, philo->id, "is thinking");
}

void   *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (is_any_dead(philo->info) == -1)
    {
        take_forks(philo);
        eat(philo);
        drop_forks(philo);
        sleeping(philo);
    }
    return (NULL);
}

void    *monitor(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        if (is_any_dead(philo->info) != -1)
        {
            philo_print(philo->info, is_any_dead(philo->info), "is dead");
            break ;
        }
        usleep(100);
    }
    return (NULL);
}