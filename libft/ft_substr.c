/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:06:47 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 20:54:09 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	amount;
	char	*substr;

	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (start + len > size)
		amount = size - start;
	else
		amount = len;
	substr = ft_calloc(amount + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, amount * sizeof(char));
	return (substr);
}
