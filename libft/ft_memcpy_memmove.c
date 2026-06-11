/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_memmove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:43:06 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 19:16:37 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = dest;
	s = src;
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	return (ft_memmove(dest, src, n));
}
