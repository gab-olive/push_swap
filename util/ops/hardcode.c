/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:57:51 by gabrielo          #+#    #+#             */
/*   Updated: 2026/06/16 17:47:47 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

// COUNT OPERATIONS TODO
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
