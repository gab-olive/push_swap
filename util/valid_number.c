/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 01:09:17 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/18 01:11:49 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <limits.h>

static long long	ft_atoll(const char *nptr)
{
	long long	accumulator;
	long long	sign;

	accumulator = 0;
	sign = 1;
	while (*nptr == 32 || (9 <= *nptr && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr == '0')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		accumulator *= 10;
		accumulator += *nptr - '0';
		nptr++;
	}
	return (accumulator * sign);
}

int	is_valid_number(const char *str)
{
	long long	num;

	if (!str || !*str)
		return (0);
	num = ft_atoll(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}
