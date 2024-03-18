/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   satoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:46:43 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/18 21:53:00 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	satoi(char *str)
{
	long	rslt;
	long	tmp;
	long	sign;

	sign = 1;
	rslt = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		tmp = rslt * 10 + *str - '0';
		if (tmp < rslt && sign == 1)
			return (__LONG_MAX__);
		if (tmp < rslt && sign == -1)
			return (__LONG_MAX__);
		rslt = tmp;
		str++;
	}
	return (sign * rslt);
}
