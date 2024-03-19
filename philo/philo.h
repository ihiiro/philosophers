/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:31:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/19 16:22:48 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>

typedef struct s_sim_values
{
	int	n;
	int	ttd;
	int	tte;
	int	tts;
	int	opt;
}		t_sim_values;

typedef struct s_threads
{
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				flag;
	pthread_mutex_t	flag_mutex;
}				t_threads;

typedef struct s_cleanup
{
	t_threads		*threads;
	pthread_mutex_t	*forks;
}					t_cleanup;

int			real_argc(int argc);

_Bool		is_digits(int argc, char **argv);

_Bool		validate_numbers(int argc, char **argv);

long		satoi(char *str);

void		main_logic(int argc, char **argv);

void		init_sim_values(int argc, char **argv, t_sim_values *sim_values);

void		clean(t_cleanup cleanup);

void		*routine(void *values);

t_threads	*init_threads(t_sim_values sim_values, t_cleanup *cleanup);

#endif