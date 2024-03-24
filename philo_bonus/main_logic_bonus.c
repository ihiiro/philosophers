/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/24 17:34:43 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "philo_bonus.h"

static void	report(char *msg, sem_t *printf_sem, int id, long start_ms)
{
	sem_wait(printf_sem);
	printf("%ld %d %s\n", get_time() - start_ms, id, msg);
	sem_post(printf_sem);
}

static void	process_routine(t_sim_values psim_values, t_sim_values *sim_values,
	int id, long start_ms)
{
	while (psim_values.opt)
	{
		sem_wait(sim_values->forks_sem);
		report("has taken a fork", sim_values->printf_sem, id, start_ms);
		sem_wait(sim_values->forks_sem);
		report("has taken a fork", sim_values->printf_sem, id, start_ms);
		report("is eating", sim_values->printf_sem, id, start_ms);
		msleep(psim_values.tte);
		sem_post(sim_values->forks_sem);
		sem_post(sim_values->forks_sem);
		psim_values.opt--;
		sem_wait(sim_values->opts_sem);
		report("is sleeping", sim_values->printf_sem, id, start_ms);
		msleep(psim_values.tts);
		report("is thinking", sim_values->printf_sem, id, start_ms);
	}
	exit(0);
}

static pid_t	*launch_processes(t_sim_values *sim_values, long start_ms)
{
	pid_t	pid;
	int		i;
	pid_t	*pids;

	i = 0;
	pids = malloc(sizeof(pid_t) * sim_values->n);
	while (i < sim_values->n)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			process_routine(*sim_values, sim_values, i + 1, start_ms);
		i++;
	}
	return (pids);
}

void	main_logic(int argc, char **argv)
{
	t_sim_values	sim_values;
	int				i;
	pid_t			*pids;

	init_sim_values(argc, argv, &sim_values);
	pids = launch_processes(&sim_values, get_time());
	while (waitpid(-1, NULL, 0) > 0)
		;
	i = -1;
	while (++i < sim_values.n)
		kill(pids[i], SIGTERM);
	sem_unlink("forks_sem");
	sem_unlink("printf_sem");
	sem_unlink("opts_sem");
	exit(EXIT_SUCCESS); // check later if pids is reachable using atexit()
}
