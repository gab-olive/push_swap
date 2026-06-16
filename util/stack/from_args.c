/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:36:05 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 17:46:04 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"

int	stack_from_list(struct s_args *args, t_stack *a)
{
	int	i;

	i = 0;
	while (i < args->size)
		if (!push_back(a, args->numbers[i++]))
			return (0);
	index_stack(a);
	return (1);
}
