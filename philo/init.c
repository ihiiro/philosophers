/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:21:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/20 14:42:47 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

t_threads	*init_threads(t_sim_values sim_values, t_cleanup *cleanup)
{
	int	i;

	i = -1;
	cleanup->threads = (t_threads *)malloc(sizeof(t_threads) * sim_values.n);
	cleanup->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* sim_values.n);
	while (++i < sim_values.n)
	{
		cleanup->threads[i].lastmeal_ms = get_time();
		cleanup->threads[i].id = i + 1;
		cleanup->threads[i].sim_values = sim_values;
		cleanup->threads[i].left_fork = &cleanup->forks[i];
		if (i + 1 == sim_values.n)
			cleanup->threads[i].right_fork = &cleanup->forks[0];
		else
			cleanup->threads[i].right_fork = &cleanup->forks[i + 1];
		cleanup->threads[i].flag = -1;
		pthread_mutex_init(&cleanup->threads[i].flag_mutex, NULL);
		pthread_mutex_init(&cleanup->forks[i], NULL);
		pthread_create(&cleanup->threads[i].thread, NULL,
			routine, &cleanup->threads[i]);
		pthread_detach(cleanup->threads[i].thread);
	}
	return (cleanup->threads);
}

void	init_sim_values(int argc, char **argv, t_sim_values *sim_values)
{
	if (real_argc(argc) == 5)
		sim_values->opt = satoi(argv[5]);
	else
		sim_values->opt = -1;
	sim_values->n = satoi(argv[1]);
	sim_values->ttd = satoi(argv[2]);
	sim_values->tte = satoi(argv[3]);
	sim_values->tts = satoi(argv[4]);
}
