/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:31:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/03/18 19:43:51 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

int		real_argc(int argc);

_Bool	is_digits(int argc, char **argv);

_Bool	main_logic(int argc, char **argv);

_Bool	check_numbers(int argc, char **argv);

long	satoi(char *str);

#endif