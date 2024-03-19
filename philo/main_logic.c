/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:47:33 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/19 15:11:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
void	main_logic(int argc, char **argv)
{
	t_sim_values	sim_values;
	t_threads		*threads;
	t_cleanup		cleanup;

	init_sim_values(argc, argv, &sim_values);
	threads = init_thread_values(sim_values, &cleanup);
	while (1);
	clean(cleanup);
}
