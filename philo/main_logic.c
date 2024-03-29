/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:47:33 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/22 15:39:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "philo.h"

static void	report(int id, int flag, long start_ms)
{
	long	timestamp_ms;

	timestamp_ms = get_time() - start_ms;
	if (flag == 4)
		printf("%ld %d has taken a fork\n", timestamp_ms, id);
	else if (flag == 1)
	{
		printf("%ld %d has taken a fork\n", timestamp_ms, id);
		printf("%ld %d is eating\n", timestamp_ms, id);
	}
	else if (flag == 2)
		printf("%ld %d is sleeping\n", timestamp_ms, id);
	else if (flag == 3)
		printf("%ld %d is thinking\n", timestamp_ms, id);
}

static int	check_death(t_sim_values sim_values, t_threads *threads,
	long start_ms)
{
	int	i;

	i = -1;
	while (++i < sim_values.n)
	{
		if (get_time() - threads[i].lastmeal_ms > sim_values.ttd
			&& threads[i].lastmeal_ms != -1)
		{
			printf("%ld %d died\n", get_time() - start_ms, i + 1);
			return (1);
		}
	}
	return (0);
}

static void	launch_monitor(t_sim_values *sim_values, t_threads *threads,
	long start_ms)
{
	int		i;

	while (1)
	{
		if (check_death(*sim_values, threads, start_ms))
			return ;
		i = -1;
		while (++i < sim_values->n)
		{
			pthread_mutex_lock(&threads[i].flag_mutex);
			if (sim_values->opts == 0)
				return ;
			if (threads[i].flag == 1)
			{
				sim_values->opts--;
				threads[i].lastmeal_ms = get_time();
			}
			if (threads[i].flag == -3)
				threads[i].lastmeal_ms = -1;
			report(i + 1, threads[i].flag, start_ms);
			threads[i].flag = -2;
			pthread_mutex_unlock(&threads[i].flag_mutex);
		}
	}
}

void	main_logic(int argc, char **argv)
{
	t_sim_values	sim_values;
	t_threads		*threads;
	t_cleanup		cleanup;
	int				i;

	init_sim_values(argc, argv, &sim_values);
	threads = init_threads(sim_values, &cleanup);
	launch_monitor(&sim_values, threads, get_time());
	i = 0;
	while (i < sim_values.n)
	{
		pthread_mutex_destroy(&cleanup.forks[i]);
		i++;
	}
	clean(cleanup);
}
