/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:01:13 by iguney            #+#    #+#             */
/*   Updated: 2025/05/24 20:26:15 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

int main(int argc, char *argv[])
{
	t_info info;

	if (check_argv(argc, argv))
		return (1);
	take_argv(&info, argc, argv);
	init_mutex(&info);
	init_philosophers(&info);
	init_threads(&info);
	// destroy_threads(&info);
	// destroy_mutex(&info);
}
