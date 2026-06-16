/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:12:10 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 12:23:36 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static struct s_stats	*get_stats_struct(void)
{
	static struct s_stats	stats = {0};

	return (&stats);
}

void	count_operation(int op)
{
	get_stats_struct()->operation_count[op]++;
	get_stats_struct()->total++;
}

int	get_operation_count(int op)
{
	return (get_stats_struct()->operation_count[op]);
}

int	get_total_operations(void)
{
	return (get_stats_struct()->total);
}
