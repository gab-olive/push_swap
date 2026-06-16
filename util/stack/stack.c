/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:42:38 by gabrielo          #+#    #+#             */
/*   Updated: 2026/06/16 12:23:11 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"
#include <stdlib.h>

void	stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	stack_clear(t_stack *stack)
{
	t_node	*curr;
	t_node	*tmp;

	curr = stack->head;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	print_stack(t_stack *stack, char *name)
{
	t_node	*curr;

	ft_printf("%s\n", name);
	curr = stack->head;
	while (curr)
	{
		ft_printf("value=%d index=%d\n", curr->value, curr->index);
		curr = curr->next;
	}
}

t_node	*push_back(t_stack *stack, int value)
{
	t_node	*new;

	new = create_node(value);
	if (!new)
		return (NULL);
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->prev = stack->tail;
		stack->tail->next = new;
		stack->tail = new;
	}
	stack->size++;
	return (new);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
