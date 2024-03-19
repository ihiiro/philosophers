/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:30:34 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/19 17:32:44 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	get_time(void)
{
	struct timeval	tv;
	long			timestamp_ms;

	gettimeofday(&tv, NULL);
	timestamp_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp_ms);
}

void	msleep(long duration_ms)
{
	long	start_ms;

	start_ms = get_time();
	while (get_time() - start_ms < duration_ms)
		;
}
