/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:51:11 by iguney            #+#    #+#             */
/*   Updated: 2025/05/23 23:35:57 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if(result > 2147483647)
			return (0);
		i++;
	}
	return (result * sign);
}

int	is_digit(char *num)
{
	while (*num)
	{
		if (!(('0' <= *num && *num <= '9') || *num == '+'))
			return (0);
		num++;
	}
	return (1);
}

int	is_any_dead(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_count)
	{
		pthread_mutex_lock(&info->philo[i].meal_mutex);
		if (get_time() - info->philo[i].last_meal_time > info->time_to_starve)
		{
			info->end_sim = 1;
			info->philo[i].is_alive = 0;
			pthread_mutex_unlock(&info->philo[i].meal_mutex);
			return (i);
		}
		pthread_mutex_unlock(&info->philo[i].meal_mutex);
		i++;
	}
	return (-1);
}

void	philo_print(t_info *info, int philo_id, char *str)
{
	pthread_mutex_lock(&info->print_mutex);
	if (info->end_sim == 0)
		printf("%zu %d %s\n", get_time() - info->start_time, philo_id + 1, str);
	pthread_mutex_unlock(&info->print_mutex);
}
