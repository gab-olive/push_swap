/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:13:58 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 20:54:22 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = NULL;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && start < end && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && end > start && ft_strchr(set, s1[end - 1]))
			end--;
		str = ft_calloc(end - start + 1, sizeof(char));
		if (!str)
			return (NULL);
		ft_memcpy(str, s1 + start, end - start);
	}
	return (str);
}
