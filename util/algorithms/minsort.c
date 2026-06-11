/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:15:11 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 20:11:29 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

int	find_min(t_stack *s)
{
	int		min;
	t_node	*curr;

	curr = s->head;
	min = curr->value;
	while (curr)
	{
		if (curr->value < min)
			min = curr->value;
		curr = curr->next;
	}
	return (min);
}

void	min_sort(t_stack *a, t_stack *b)
{
	while (a->size > 0)
	{
		while (a->head->value != find_min(a))
			ra(a);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b); 
}
