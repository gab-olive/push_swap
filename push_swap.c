/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:29:51 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 18:15:58 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libftprintf.h"
#include "util.h"
#include <stdlib.h>

typedef void	(*t_sorting_func)(t_stack *a, t_stack *b);

static t_sorting_func	pick_algorithm(struct s_args *args)
{
	double	disorder;

	disorder = compute_disorder(args->numbers, args->size);
	if (args->flags & ADAPTIVE)
	{
		if (disorder < 0.2)
			return (min_sort);
		else if (disorder < 0.5)
			return (chunk_sort);
		else
			return (radix_sort);
	}
	else
	{
		if (args->flags & SIMPLE)
			return (min_sort);
		if (args->flags & MEDIUM)
			return (chunk_sort);
		if (args->flags & COMPLEX)
			return (radix_sort);
	}
	return (chunk_sort);
}

static int	error_out(void)
{
	ft_printf("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	struct s_args	args;
	t_stack			stack_a;
	t_stack			stack_b;
	t_sorting_func	func;

	if (argc == 1)
		return (0);
	stack_init(&stack_a);
	stack_init(&stack_b);
	if (!initialize_args(&args, argc, argv))
		error_out();
	stack_from_list(&args, &stack_a);
	func = pick_algorithm(&args);
	if (!func)
		error_out();
	func(&stack_a, &stack_b);
	if (args.flags & BENCH)
		bench(&args);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	free(args.numbers);
}
