/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:17:16 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 16:27:03 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "util.h"

void	swap(t_stack *s)
{
	int	tmp_val;
	int	tmp_idx;

	if (!s || s->size < 2)
		return ;
	tmp_val = s->head->value;
	s->head->value = s->head->next->value;
	s->head->next->value = tmp_val;
	tmp_idx = s->head->index;
	s->head->index = s->head->next->index;
	s->head->next->index = tmp_idx;
}

void	sa(t_stack *a)
{
	swap(a);
	count_operation(SA);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	count_operation(SB);
	ft_printf("sb\n");
}