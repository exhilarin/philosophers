#ifndef PHILO_H
# define PHILO_H

#include "struct.h"

// Utils
size_t	get_time(void);
int		is_digit(char *num);
int		ft_atoi(const char *str);
void	philo_print(t_philo *philo, int id, char *str);

// Init
void	smart_sleep(size_t wait_time);
void	init_mutex(t_info *info);
void	init_philosophers(t_info *info);
void	init_threads(t_info *info);

// // Actions
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	drop_forks(t_philo *philo);
void	sleeping(t_philo *philo);

// // Control
int     check_argv(int argc, char *argv[]);
void    take_argv(t_info *info, int argc, char *argv[]);
void	*monitor(void *arg);
void	*philo_routine(void *arg);

// Termninate
int     should_stop(t_info *info);
int	    check_all_ate(t_info *info);
int	    is_any_dead(t_info *info);
void	destroy_mutex(t_info *info);

#endif