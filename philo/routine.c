/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:17:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/20 13:59:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

#include <unistd.h>

void	set_flag(int val, int *flag, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*flag = val;
	pthread_mutex_unlock(mutex);
}

void	*routine(void *values)
{
	t_threads	*vals;

	vals = (t_threads *)values;
	while (1)
	{
		if (vals->id % 2 == 0)
			pthread_mutex_lock(vals->left_fork);
		else
			pthread_mutex_lock(vals->right_fork);
		set_flag(4, &vals->flag, &vals->flag_mutex);
		while (1)
		{
			pthread_mutex_lock(&vals->flag_mutex);
			if (vals->flag == -2)
			{
				pthread_mutex_unlock(&vals->flag_mutex);
				break ;
			}
			pthread_mutex_unlock(&vals->flag_mutex);
		}
		if (vals->id % 2 == 0)
			pthread_mutex_lock(vals->right_fork);
		else
			pthread_mutex_lock(vals->left_fork);
		set_flag(1, &vals->flag, &vals->flag_mutex);
		msleep(vals->sim_values.tte);
		pthread_mutex_unlock(vals->left_fork);
		pthread_mutex_unlock(vals->right_fork);
		set_flag(2, &vals->flag, &vals->flag_mutex);
		msleep(vals->sim_values.tts);
		set_flag(3, &vals->flag, &vals->flag_mutex);
	}
	return (NULL);
}
