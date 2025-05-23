/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:01:13 by iguney            #+#    #+#             */
/*   Updated: 2025/05/22 18:47:32 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

int main(int argc, char *argv[])
{
	t_info info;
	t_philo philo;

	if (check_argv(argc, argv))
		return (1);
	take_argv(&info, argc, argv);
	init_mutex(&info);
	init_philosophers(&philo, &info);
	init_threads(&info);
	// destroy_threads(&info);
	destroy_mutex(&info);
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
	info->start_time = get_time();
}

// TODO: Thread oluştur.
// TODO: Monitör thread oluştur.
// TODO: Rutin fonksiyonu yaz.
