/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:49:52 by iguney            #+#    #+#             */
/*   Updated: 2025/05/31 19:48:05 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (should_stop(philo))
	{
		take_forks(philo);
		eating(philo);
		drop_forks(philo);
		sleeping(philo);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_info *info;
	
	info = (t_info *)arg;
	while (1)
	{
		pthread_mutex_lock(&info->stop_mutex);
		if (info->end_sim == 1)
		{
			pthread_mutex_unlock(&info->stop_mutex);
			pthread_mutex_lock(&info->print_mutex);
			printf("%zu %s\n", get_time() - info->start_time, "Simulation ended successfully");
			pthread_mutex_unlock(&info->print_mutex);
			return (NULL);
		}
		if (info->end_sim == 2)
		{
			pthread_mutex_unlock(&info->stop_mutex);
			pthread_mutex_lock(&info->print_mutex);
			printf("%zu %d %s\n", get_time() - info->start_time, info->dead + 1, "dead");
			pthread_mutex_unlock(&info->print_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&info->stop_mutex);
	}
}

int	should_stop(t_philo *philo)
{
    pthread_mutex_lock(&philo->info->eat_mutex);
	if (philo->info->all_ate_flag == philo->info->philo_count)
	{
        pthread_mutex_lock(&philo->info->stop_mutex);
        philo->info->end_sim = 1;
        pthread_mutex_unlock(&philo->info->stop_mutex);
        pthread_mutex_unlock(&philo->info->eat_mutex);
		return (0);
	}
	if ((get_time() - (size_t)philo->last_meal_time) > (size_t)(philo->info->time_to_starve))
	{
        pthread_mutex_lock(&philo->info->stop_mutex);
		philo->info->dead = philo->id;
        philo->info->end_sim = 2;
        pthread_mutex_unlock(&philo->info->stop_mutex);
        pthread_mutex_unlock(&philo->info->eat_mutex);
		return (0);
	}
    pthread_mutex_unlock(&philo->info->eat_mutex);
	return (1);
}

int	check_argv(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (printf("Error: 5 or 6 arguments required.\n"), 1);
	while (argv[++i])
	{
		if (!is_digit(argv[i]) || (ft_atoi(argv[i]) < 1))
			return (printf("Error: Invalid Input!\n"), 1);
	}
	return (0);
}

void    take_argv(t_info *info, int argc, char *argv[])
{
	info->philo_count = ft_atoi(argv[1]);
	info->time_to_starve = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat_count = ft_atoi(argv[5]);
	else
		info->must_eat_count = -1;
	info->end_sim = 0;
	info->all_ate_flag = 0;
}