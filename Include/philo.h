/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 07:22:00 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/06/03 07:07:19 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"

/* utils.c */
size_t	get_time(void);
int		is_digit(char *num);
int		ft_atoi(const char *str);
void	philo_print(t_philo *philo, int id, char *str);
void	smart_sleep(size_t wait_time);

/* initialize.c */
void	init_mutex(t_info *info);
void	init_philosophers(t_info *info);
void	init_threads(t_info *info);

/* actions.c */
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	drop_forks(t_philo *philo);
void	sleeping(t_philo *philo);

/* control.c */
int		check_argv(int argc, char *argv[]);
void	take_argv(t_info *info, int argc, char *argv[]);
void	*monitor(void *arg);
void	*philo_routine(void *arg);

/* terminate.c */
int		should_stop(t_info *info);
int		check_all_ate(t_info *info);
int		is_any_dead(t_info *info);
void	end_sim(t_info *info);

#endif
