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
	pthread_t		*thread;

} t_philo;


typedef struct s_info
{
	pthread_t thread;

	int		philo_id;
	int		philo_count;
	int		meals_count;
	int		meals_left;

	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	time_to_starve;
	size_t	is_any_dead;
	size_t	start_time;

	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	print_lock;

}	t_info;

#endif