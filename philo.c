/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:01:13 by iguney            #+#    #+#             */
/*   Updated: 2025/05/11 07:25:48 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/philo.h"

int main(int argc, char *argv[])
{
	t_info *info;

	info = malloc(sizeof(t_info));
	check_argv(argv);
	take_argv(info, argc, argv);
	
}
