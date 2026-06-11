/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:43:44 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/17 01:38:33 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
