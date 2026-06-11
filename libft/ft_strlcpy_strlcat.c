/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_strlcat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:55:32 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/20 22:07:59 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (index < (size - 1) && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	if (size > 0)
	{
		dst[index] = 0;
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		src_length;
	size_t		dst_length;
	char		*output;
	size_t		capacity;

	src_length = ft_strlen(src);
	capacity = size;
	output = dst;
	while (capacity-- != 0 && *output != '\0')
		output++;
	dst_length = output - dst;
	capacity = size - dst_length;
	if (capacity == 0)
		return (dst_length + src_length);
	while (*src)
	{
		if (capacity != 1)
		{
			*output++ = *src;
			capacity--;
		}
		src++;
	}
	*output = 0;
	return (dst_length + src_length);
}
