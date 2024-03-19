/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:17:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/19 15:38:52 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

#include <stdio.h>

void	*routine(void *values)
{
	t_threads	*threads = (t_threads *)values;

	printf("working!\n");
	return (NULL);
}
