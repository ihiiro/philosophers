/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:25:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/24 21:43:03 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "philo_bonus.h"

void	init_monitor(int id, t_monitor *data, t_sim_values *sim_values,
	t_sim_values psim_values)
{
	pthread_t	monitor;

	data->lastmeal_sem = sem_open("lastmeal_sem", O_CREAT, 0644, 1);
	data->lastmeal_ms = get_time();
	data->ttd = psim_values.ttd;
	data->printf_sem = sim_values->printf_sem;
	data->n = psim_values.n;
	data->id = id;
	pthread_create(&monitor, NULL, monitor_routine, data);
	pthread_detach(monitor);
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
	sem_unlink("forks_sem");
	sem_unlink("printf_sem");
	sem_unlink("opts_sem");
	sim_values->forks_sem = sem_open("forks_sem", O_CREAT, 0644, sim_values->n);
	sim_values->printf_sem = sem_open("printf_sem", O_CREAT, 0644, 1);
	sim_values->opts_sem = sem_open("opts_sem", O_CREAT, 0644,
			sim_values->n * sim_values->opt);
}
