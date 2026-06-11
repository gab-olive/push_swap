/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:59:14 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 17:35:11 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;

	new_string = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s, ft_strlen(s) + 1);
	return (new_string);
}
