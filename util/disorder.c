/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:30:31 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 17:45:14 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(int *numbers, size_t size)
{
	double	mistakes;
	double	total_pairs;
	size_t	i;
	size_t	j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (numbers[i] > numbers[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
