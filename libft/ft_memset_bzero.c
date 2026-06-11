/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_bzero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:37:40 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 00:08:43 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	index;

	str = s;
	index = 0;
	while (index < n)
	{
		str[index] = c;
		index++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
