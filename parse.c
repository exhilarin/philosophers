/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 07:49:20 by iguney            #+#    #+#             */
/*   Updated: 2025/05/14 17:49:49 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

void	check_argv(char *argv[])
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!is_digit(argv[i]))
			return (printf("Invalid Input!\n"), exit(0));
		if (ft_atoi(argv[i]) < 0)
			return (printf("Invalid Input!\n"), exit(0));
		if (INT_MAX < ft_atoi(argv[i])
			|| 1 > ft_atoi(argv[i]))
			return (printf("Invalid Input!\n"), exit(0));
	}
}

void    take_argv(t_info *info, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (printf("Invalid Input!\n"), exit(0));
	info->philo_count = ft_atoi(argv[1]);
	info->time_to_starve = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->meals_count = ft_atoi(argv[5]);
	info->is_any_dead = 0;
	info->start_time = init_time();
}
