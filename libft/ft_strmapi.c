/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:29:49 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 17:35:27 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	index;

	index = 0;
	new_string = ft_strdup(s);
	if (new_string == NULL)
		return (NULL);
	while (new_string[index])
	{
		new_string[index] = (*f)(index, new_string[index]);
		index++;
	}
	return (new_string);
}
