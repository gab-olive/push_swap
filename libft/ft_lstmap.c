/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:58:08 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/27 11:04:13 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = ft_lstnew((*f)(lst->content));
	if (new_lst == NULL)
		return (NULL);
	if (lst->next)
	{
		new_lst->next = ft_lstmap(lst->next, f, del);
		if (new_lst->next == NULL)
		{
			ft_lstdelone(new_lst, del);
			new_lst = NULL;
		}
	}	
	return (new_lst);
}
