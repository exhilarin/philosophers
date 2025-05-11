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

typedef struct s_philo
{
	
} t_philo;

typedef struct s_info
{
	int	philo_count;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_starve;
	int	is_any_death;
	int start_time;
	int meals_count;
}	t_info;

#endif