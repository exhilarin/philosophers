/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:51:11 by iguney            #+#    #+#             */
/*   Updated: 2025/05/31 19:39:49 by ilyas-guney      ###   ########.fr       */
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

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return ((size_t)time.tv_sec * 1000 + (size_t)time.tv_usec / 1000);
}

void	smart_sleep(size_t wait_time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < wait_time)
		usleep(500);
}

void	philo_print(t_philo *philo, int id, char *str)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->stop_mutex);
	if (philo->info->end_sim == 0)
		printf("%zu %d %s\n", get_time() - philo->info->start_time, id + 1, str);
	pthread_mutex_unlock(&philo->info->print_mutex);
	pthread_mutex_unlock(&philo->info->stop_mutex);
}