/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcache.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 01:30:38 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/18 01:48:35 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "push_swap.h"

typedef struct s_opcache_node
{
	enum e_operations	op;
	long				state_hash;
	struct s_opcache_node	*next;
	struct s_opcache_node	*prev;
}	t_opcache_node;

typedef struct s_opcache
{
	t_opcache_node	*head;
	t_opcache_node	*tail;
}	t_opcache;

static t_opcache	*get_opcache(void)
{
	static t_opcache	cache = {0};

	return (&cache);
}

static t_opcache_node	*find_match(t_opcache_node *tail)
{
	t_opcache_node	*current;

	current = tail;
	while (current)
	{
		if (current->state_hash == tail->state_hash)
			return (current);
		current = current->prev;
	}
	return (NULL);
}

int	compute_state_hash(t_stack *a, t_stack *b)
{
	long	h;
	static long	prime = 31;
	t_node	*current;

	h = 17;
	h = (h * prime) + a->size;
	h = (h * prime) + b->size;
	current = a->head;
	while (current)
	{
		h = (h * prime) + current->value;
		current = current->next;
	}
}

int	do_operation(enum e_operations op, t_stack *a, t_stack *b)
{
	t_opcache *cache;
	t_opcache_node *new_node;

	cache = get_opcache();
	new_node = malloc(sizeof(t_opcache_node));
	if (!new_node)
		return (0);
	new_node->op = op;
	new_node->state_hash = compute_state_hash(a, b);
	new_node->next = NULL;
	new_node->prev = find_match(cache->tail);
	if (cache->head == NULL)
		cache->head = new_node;
	else
		cache->tail->next = new_node;
	cache->tail = new_node;
	return (1);
}
