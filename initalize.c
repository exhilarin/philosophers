/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:18:14 by iguney            #+#    #+#             */
/*   Updated: 2025/05/11 07:52:39 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

long	init_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (time);
}

void	init_threads(void)
{
	
}

void	init_mutex(void)
{
	
}

void	init_philosophers(void)
{

}