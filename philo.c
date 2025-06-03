/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:01:13 by iguney            #+#    #+#             */
/*   Updated: 2025/06/03 07:06:57 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (check_argv(argc, argv))
		return (1);
	take_argv(&info, argc, argv);
	init_mutex(&info);
	init_philosophers(&info);
	init_threads(&info);
	end_sim(&info);
}
