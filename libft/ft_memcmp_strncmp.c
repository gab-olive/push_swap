/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_strncmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:19:40 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 23:56:50 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			offset;

	offset = 0;
	if (n <= 0)
		return (0);
	while (*((unsigned char *)s1) == *((unsigned char *)s2) \
			&& offset != (n - 1))
	{
		s1++;
		s2++;
		offset++;
	}
	return ((*((unsigned char *)s1) - *((unsigned char *)s2)));
}
