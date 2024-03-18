/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:28:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/18 18:30:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_int8_t.h>
#include <stddef.h>

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
