/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:52:12 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/06 19:21:48 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

int	get_pos(t_stack *b, int target)
{
	int		pos;
	t_node	*tmp;

	tmp = b->head;
	pos = 0;
	while (tmp->index != target)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	push_all_a(t_stack *a, t_stack *b)
{
	int	i;
	int	position;
	int	target;

	target = b->size - 1;
	while (b->size > 0)
	{
		if (b->head && b->head->index == target - 1)
			pa(a, b);
		position = get_pos(b, target);
		if (position <= b->size / 2)
		{
			while (b->head->index != target)
				rb(b);
		}
		else
		{
			while (b->head->index != target)
				rrb(b);
		}
		pa(a, b);
		if (a->size > 1 && a->head->index > a->head->next->index)
		{
			sa(a);
			target--;
		}
		target--;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk;
	int	i;

	i = 0;
	chunk = int_sqrt(a->size);
	while (a->head)
	{
		if (a->head->index <= i)
		{
			pb(a, b);
			if (a->head && a->head->index > (i + chunk))
				rr(a, b);
			else
				rb(b);
			i++;
		}
		else if (a->head->index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_all_a(a, b);
}
