/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 07:30:00 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/06/03 07:04:58 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_philo	t_philo;

typedef struct s_info
{
	int				philo_count;
	int				time_to_eat;
	int				time_to_sleep;
	size_t			time_to_starve;
	int				must_eat_count;
	int				all_ate_flag;
	int				end_sim;
	size_t			start_time;

	pthread_t		*thread;
	pthread_t		monitor_thread;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	eat_mutex;

	t_philo			*philo;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	size_t			last_meal_time;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	t_info			*info;
}	t_philo;

#endif
