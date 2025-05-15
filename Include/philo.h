#ifndef PHILO_H
# define PHILO_H

#include "struct.h"

// Utils
int		is_digit(char *num);
int		ft_atoi(const char *str);

// Parse
int     check_argv(int argc, char *argv[]);
int     take_argv(t_info *philo, int argc, char *argv[]);

// Init
long	init_time(void);
void	init_mutex(t_info *info);
void	init_philosophers(t_info *info);

// Termninate
void	destroy_mutex(t_info *info);

#endif