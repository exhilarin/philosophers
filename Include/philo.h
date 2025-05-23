#ifndef PHILO_H
# define PHILO_H

#include "struct.h"

// Utils
int		is_digit(char *num);
int		ft_atoi(const char *str);
int     is_any_dead(t_info *info);
void	philo_print(t_info *info, int philo_id, char *str);

// Parse
int     check_argv(int argc, char *argv[]);
void    take_argv(t_info *philo, int argc, char *argv[]);

// Init
long	get_time(void);
void	smart_sleep(size_t wait_time);
void	init_mutex(t_info *info);
void	init_philosophers(t_philo *philo, t_info *info);
void	init_threads(t_info *info);

// Actions
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	drop_forks(t_philo *philo);
void	sleeping(t_philo *philo);


// Monitor
void	*monitor(void *arg);
void	*philo_routine(void *arg);

// Termninate
void	destroy_mutex(t_info *info);

#endif