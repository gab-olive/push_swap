/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:16:16 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/06 17:50:19 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

static void	push(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->size == 0)
		return ;
	tmp = b->head;
	b->head = b->head->next;
	if (b->head)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	b->size--;
	tmp->next = a->head;
	if (a->head)
		a->head->prev = tmp;
	else
		a->tail = tmp;
	a->head = tmp;
	a->size++;
}

void	pb(t_stack *a, t_stack *b)
{
	count_operation(PB);
	push(b, a);
	ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	count_operation(PA);
	push(a, b);
	ft_printf("pa\n");
}
