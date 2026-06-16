/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:02:59 by gabrielo          #+#    #+#             */
/*   Updated: 2026/06/16 17:48:52 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

void	index_stack(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		count;

	current = a->head;
	while (current != NULL)
	{
		count = 0;
		compare = a->head;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	bits;

	if (stack->size <= 1)
		return (0);
	max_index = stack->size - 1;
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;
	int	full_size;

	index_stack(a);
	max_bits = get_max_bits(a);
	full_size = a->size;
	i = 0;
	while (i < max_bits && !is_sorted(a))
	{
		j = 0;
		while (j < full_size)
		{
			if (((a->head->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
