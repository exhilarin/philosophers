#ifndef PHILO_H
# define PHILO_H

#include "struct.h"

int		is_digit(char *num);
int		ft_atoi(const char *str);

long    init_time(void);
void	check_argv(char *argv[]);
void    take_argv(t_info *philo, int argc, char *argv[]);

#endif