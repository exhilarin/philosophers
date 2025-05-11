/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 07:49:20 by iguney            #+#    #+#             */
/*   Updated: 2025/05/11 18:24:34 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void	check_argv(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 1;
		if (!is_digit(argv[i]))
			return (printf("Invalid Input!"), NULL);
		if (ft_atoi(argv[i]) < 0)
			return (printf("Invalid Input!"), NULL);
		if (INT_MAX < ft_atoi(argv[i])
			|| INT_MIN > ft_atoi(argv[i]))
			return (printf("Invalid Input!"), NULL);
	}
}

void    take_argv(t_info *info, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (printf("Invalid Input!"), NULL);
	info->philo_count = ft_atoi(argv[1]);
	info->time_to_starve = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->meals_count = ft_atoi(argv[5]);
	info->is_any_dead = 0;
	info->start_time = init_time();
	
}