/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:31:21 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 20:15:55 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	accumulator;
	int	sign;

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
