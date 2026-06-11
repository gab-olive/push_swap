/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:26:13 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/06 21:54:06 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd/ft_printf_fd.h"
#include "util.h"
#include <unistd.h>

static char	*get_strategy_str(struct s_args *args)
{
	double	disorder;

	disorder = compute_disorder(args->numbers, args->size);
	if (args->flags & SIMPLE)
			return ("Simple / O(n²)");
	else if (args->flags & MEDIUM)
		return ("Medium / O(n√n)");
	else if (args->flags & COMPLEX)
		return ("Complex / O(n log n)");
	else if (disorder < 0.2)
		return ("Adaptive / O(n²)");
	else if (disorder < 0.5)
		return ("Adaptive / O(n√n)");
	else
		return ("Adaptive / O(n log n)");
}

#include <stdio.h>

void	bench(struct s_args *args)
{
	double	d;
	int		disorder;
	int		fractions;
	char	*buf;

	d = compute_disorder(args->numbers, args->size) * 10000;
	disorder = d;
	fractions = disorder % 100;
	disorder = disorder / 100;
	ft_printf_fd(STDERR_FILENO, "[bench] disorder: %d.%d%%\n", disorder, fractions);
	ft_printf_fd(STDERR_FILENO, "[bench] strategy: %s\n", get_strategy_str(args));
	ft_printf_fd(STDERR_FILENO, "[bench] total_ops: %d\n", get_total_operations());
	ft_printf_fd(STDERR_FILENO, "[bench]: ");
	ft_printf_fd(STDERR_FILENO, "sa: %d ", get_operation_count(SA));
	ft_printf_fd(STDERR_FILENO, "sb: %d ", get_operation_count(SB));
	ft_printf_fd(STDERR_FILENO, "ss: %d ", get_operation_count(SS));
	ft_printf_fd(STDERR_FILENO, "pa: %d ", get_operation_count(PA));
	ft_printf_fd(STDERR_FILENO, "pb: %d\n", get_operation_count(PB));
	ft_printf_fd(STDERR_FILENO, "[bench]: ra: %d ", get_operation_count(RA));
	ft_printf_fd(STDERR_FILENO, "rb: %d ", get_operation_count(RB));
	ft_printf_fd(STDERR_FILENO, "rr: %d ", get_operation_count(RR));
	ft_printf_fd(STDERR_FILENO, "rra: %d ", get_operation_count(RRA));
	ft_printf_fd(STDERR_FILENO, "rrb: %d ", get_operation_count(RRB));
	ft_printf_fd(STDERR_FILENO, "rrr: %d\n", get_operation_count(RRR));
}
