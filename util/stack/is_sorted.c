/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-08 22:34:46 by gabriel           #+#    #+#             */
/*   Updated: 2026-06-08 22:34:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node *tmp;

	if (!a || !a->head || a->size < 2)
        return (1);
	tmp = a->head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}