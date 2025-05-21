/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:49:52 by iguney            #+#    #+#             */
/*   Updated: 2025/05/21 07:51:21 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void    *monitor(void *arg)
{
    t_info *info;
    int i;

    info = (t_info *)arg;
    while (1)
    {
        i = -1;
        while (++i < info->philo_count)
        {
            pthread_mutex_lock(&info->stop_mutex);
            if (info->end_sim == 1)
            {
                pthread_mutex_unlock(&info->stop_mutex);
                return (NULL);
            }
            pthread_mutex_unlock(&info->stop_mutex);
        }
    }
    return (NULL);
}

void    *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->philo_id % 2 == 0)
        usleep(100);
    while (1)
    {
        take_forks(philo);
        eating(philo);
        drop_forks(philo);
        sleeping(philo);
    }
    return (NULL);
}

void    take_right_fork(t_philo *philo)
{
    philo_print(philo->info, philo->philo_id, "is eating");
    smart_sleep(philo->info->time_to_eat);
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->meal_mutex);
    philo_print(philo->info, philo->philo_id, "has eaten");
}
void    take_left_fork(t_philo *philo)
{
    philo_print(philo->info, philo->philo_id, "is eating");
    smart_sleep(philo->info->time_to_eat);
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->meal_mutex);
    philo_print(philo->info, philo->philo_id, "has eaten");
}
