/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:28:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/18 20:02:29 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "philo.h"

_Bool	validate_numbers(int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = satoi(argv[i]);
		if (n == 0 || n > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	real_argc(int argc)
{
	if (argc == 0)
		return (0);
	return (argc - 1);
}

_Bool	is_digits(int argc, char **argv)
{
	size_t	argv_iter;
	int		argc_iter;

	argc = real_argc(argc);
	argc_iter = 0;
	while (argc_iter++ < argc)
	{
		argv_iter = 0;
		while (argv[argc_iter][argv_iter])
		{
			if (argv[argc_iter][argv_iter] < '0'
				|| argv[argc_iter][argv_iter] > '9')
				return (0);
			argv_iter++;
		}
	}
	return (1);
}
