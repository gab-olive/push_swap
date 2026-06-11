/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:27:55 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 20:07:25 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	left_little;

	if (*little != 0)
	{
		left_little = ft_strlen(little + 1);
		while (1)
		{
			while (1)
			{
				if (len-- < 1)
					return (NULL);
				if (*big == 0)
					return (NULL);
				if (*big++ == *little)
					break ;
			}
			if (left_little > len)
				return (NULL);
			if (ft_strncmp(big, little + 1, left_little) == 0)
				return ((char *)big - 1);
		}
	}
	return ((char *)big);
}
