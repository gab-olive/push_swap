/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:12:10 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/06 21:52:05 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	struct s_stats	*get_stats_struct(void)
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

int	get_total_operations()
{
	return (get_stats_struct()->total);
}
