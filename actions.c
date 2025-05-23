/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:04:56 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/05/24 02:09:32 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void    take_forks(t_info *info)
{
    if (info->philo->id % 2 == 0)
    {
        pthread_mutex_lock(info->philo->right_fork);
        philo_print(info, info->philo->id, "has taken a fork");
        pthread_mutex_lock(info->philo->left_fork);
        philo_print(info, info->philo->id, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(info->philo->left_fork);
        philo_print(info, info->philo->id, "has taken a fork");
        pthread_mutex_lock(info->philo->right_fork);
        philo_print(info, info->philo->id, "has taken a fork");
    }
}
void    eating(t_info *info)
{
    pthread_mutex_lock(&info->philo->meal_mutex);
    info->philo->last_meal_time = get_time();
    philo_print(info, info->philo->id, "is eating");
    smart_sleep(info->time_to_eat);
    pthread_mutex_unlock(&info->philo->meal_mutex);
    info->philo->meals_eaten++;
    if (info->must_eat_count != -1 && info->philo->meals_eaten == info->must_eat_count)
        info->all_ate_flag++;
}

void    drop_forks(t_info *info)
{
    pthread_mutex_unlock(info->philo->left_fork);
    pthread_mutex_unlock(info->philo->right_fork);
}

void    sleeping(t_info *info)
{
    philo_print(info, info->philo->id, "is sleeping");
    smart_sleep(info->time_to_sleep);
    philo_print(info, info->philo->id, "is thinking");
}
