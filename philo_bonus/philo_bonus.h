/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:31:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/24 21:43:49 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <semaphore.h>

typedef struct s_sim_values
{
	int		n;
	int		ttd;
	int		tte;
	int		tts;
	int		opt;
	sem_t	*forks_sem;
	sem_t	*printf_sem;
	sem_t	*opts_sem;
	int		end_sim;
	sem_t	*endsim_sem;
	pid_t	*pids;
}		t_sim_values;

typedef struct s_threads
{
	pthread_t		thread;
	t_sim_values	sim_values;
	int				id;
	long			lastmeal_ms;
	int				opt;
	pthread_mutex_t	opt_mutex;
}				t_threads;

typedef struct s_cleanup
{
	t_threads		*threads;
	pthread_mutex_t	*forks;
}					t_cleanup;

typedef struct s_monitor
{
	sem_t	*lastmeal_sem;
	int		id;
	long	start_ms;
	sem_t	*endsim_sem;
	long	lastmeal_ms;
	int		ttd;
	sem_t	*printf_sem;
	int		*end_sim;
	int		n;
}			t_monitor;

int			real_argc(int argc);

_Bool		is_digits(int argc, char **argv);

_Bool		validate_numbers(int argc, char **argv);

long		satoi(char *str);

long		get_time(void);

void		main_logic(int argc, char **argv);

void		init_sim_values(int argc, char **argv, t_sim_values *sim_values);

void		clean(t_cleanup cleanup);

void		msleep(long duration_ms);

void		init_monitor(int id, t_monitor *data, t_sim_values *sim_values,
				t_sim_values psim_values);

void		*monitor_routine(void *data);

t_threads	*init_threads(t_sim_values sim_values, t_cleanup *cleanup);

#endif