/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:21:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/19 00:34:19 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "philo.h"

t_threads	*init_thread_values(t_sim_values sim_values, t_cleanup *cleanup)
{
	int				i;
	t_threads		*threads;
	pthread_mutex_t	*forks;

	i = 0;
	threads = (t_threads *)malloc(sizeof(t_threads) * sim_values.n);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * sim_values.n);
	cleanup->threads = threads;
	cleanup->forks = forks;
	while (i < sim_values.n)
	{
		threads[i].id = i + 1;
		threads[i].left_fork = &forks[i];
		if (threads[i].id == sim_values.n)
			threads[i].right_fork = &forks[0];
		else
			threads[i].right_fork = &forks[i + 1];
		pthread_mutex_init(&forks[i], NULL);
		pthread_create(&threads[i].thread, NULL, routine, &threads[i]);
		// sleep here to allow creation time for previous thread
		pthread_detach(threads[i].thread);
		i++;
	}
	return (threads);
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
