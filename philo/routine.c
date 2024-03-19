/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:17:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/19 17:10:00 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

#include <unistd.h>

void	*routine(void *values)
{
	t_threads	*vals = (t_threads *)values;

	while (1)
	{
		pthread_mutex_lock(&vals->flag_mutex);
		vals->flag = 0;
		pthread_mutex_unlock(&vals->flag_mutex);
		usleep(vals->sim_values.tte * 1000);
		pthread_mutex_lock(&vals->flag_mutex);
		vals->flag = 1;
		pthread_mutex_unlock(&vals->flag_mutex);
		usleep(vals->sim_values.tts * 1000);
		pthread_mutex_lock(&vals->flag_mutex);
		vals->flag = 2;
		pthread_mutex_unlock(&vals->flag_mutex);
	}
	return (NULL);
}
