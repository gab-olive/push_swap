/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:17:33 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/09 08:46:59 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

static void	rotate(t_stack *s)
{
	s->tail->next = s->head;
	s->head->prev = s->tail;
	s->head = s->head->next;
	s->head->prev = NULL;
	s->tail = s->tail->next;
	s->tail->next = NULL;
}

void	ra(t_stack *a)
{
	count_operation(RA);
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	count_operation(RB);
	rotate(b);
	ft_printf("rb\n");
}
void	rr(t_stack *a, t_stack *b)
{
	int executed;

	executed = 0;
	if (a && a->size >= 2)
	{
		rotate(a);
		executed = 1;
	}
	if (b && b->size >= 2)
	{
		rotate(b);
		executed = 1;
	}
	if (executed)
	{
		count_operation(RR);
		ft_printf("rr\n");
	}
}