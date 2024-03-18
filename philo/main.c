/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:37:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/18 20:01:47 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	if (real_argc(argc) > 5 || real_argc(argc) < 4)
		return (EXIT_FAILURE);
	if (!is_digits(argc, argv))
		return (EXIT_FAILURE);
	if (!validate_numbers(argc, argv))
		return (EXIT_FAILURE);
	main_logic(argc, argv);
	return (EXIT_SUCCESS);
}
