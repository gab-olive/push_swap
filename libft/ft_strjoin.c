/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:11:35 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/15 22:10:08 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = ft_calloc(size, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcat(new_str, s1, size);
	ft_strlcat(new_str, s2, size);
	return (new_str);
}
