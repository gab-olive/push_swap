/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:29:49 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 12:19:48 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

static void	reverse_rotate(t_stack *s)
{
	s->head->prev = s->tail;
	s->tail->next = s->head;
	s->tail = s->tail->prev;
	s->tail->next = NULL;
	s->head = s->head->prev;
	s->head->prev = NULL;
}

void	rra(t_stack *a)
{
	count_operation(RRA);
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	count_operation(RRB);
	reverse_rotate(b);
	ft_printf("rrb\n");
}
