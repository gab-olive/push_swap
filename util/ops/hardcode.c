/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:57:51 by gabrielo          #+#    #+#             */
/*   Updated: 2026/06/16 12:19:43 by gabrielo         ###   ########.fr       */
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
	if ((a_val < b_val) && (b_val < c_val)) // 1-2-3
		return ;
	if ((a_val < c_val) && (c_val < b_val)) // 1-3-2
	{
		sa(a);
		ra(a);
	}
	else if ((b_val < a_val) && (a_val < c_val)) // 2-1-3
		sa(a);
	else if ((c_val < a_val) && (a_val < b_val)) // 2-3-1
		rra(a);
	else if ((b_val < c_val) && (c_val < a_val)) // 3-1-2
		ra(a);
	else if ((c_val < b_val) && (b_val < a_val)) // 3-2-1
	{
		sa(a);
		rra(a);
	}
}
