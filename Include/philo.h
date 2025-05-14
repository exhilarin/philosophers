#ifndef PHILO_H
# define PHILO_H

#include "struct.h"

// Utils
int		is_digit(char *num);
int		ft_atoi(const char *str);

// Parse
void	check_argv(char *argv[]);
void	take_argv(t_info *philo, int argc, char *argv[]);

// Init
long	init_time(void);


#endif