/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:57:51 by gabrielo          #+#    #+#             */
/*   Updated: 2026/06/18 16:20:52 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

static int	get_min_pos(t_stack *stack)
{
	t_node	*tmp;
	int		min_val;
	int		min_pos;
	int		i;

	tmp = stack->head;
	min_val = tmp->value;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	sort_three(t_stack *a)
{
	int	a_val;
	int	b_val;
	int	c_val;

	a_val = a->head->value;
	b_val = a->head->next->value;
	c_val = a->head->next->next->value;
	if ((a_val < b_val) && (b_val < c_val))
		return ;
	if ((a_val < c_val) && (c_val < b_val))
	{
		sa(a);
		ra(a);
	}
	else if ((b_val < a_val) && (a_val < c_val))
		sa(a);
	else if ((c_val < a_val) && (a_val < b_val))
		rra(a);
	else if ((b_val < c_val) && (c_val < a_val))
		ra(a);
	else if ((c_val < b_val) && (b_val < a_val))
	{
		sa(a);
		rra(a);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	while (a->size > 3)
	{
		pos = get_min_pos(a);
		size = a->size;
		if (pos <= size / 2)
			while (pos--)
				ra(a);
		else
			while (pos++ < size)
				rra(a);
		if (is_sorted(a))
			break ;
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	small_sort_check(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	return ;
}
