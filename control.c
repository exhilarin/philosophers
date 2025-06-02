/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:49:52 by iguney            #+#    #+#             */
/*   Updated: 2025/06/02 21:48:42 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!should_stop(philo->info))
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
	while (!should_stop(info))
	{
		if (check_all_ate(info) || is_any_dead(info))
			break;
	}
	return (NULL);
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