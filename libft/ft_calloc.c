/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:56:01 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/27 11:43:01 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > INT_MAX / size)
		return (NULL);
	array = malloc(nmemb * size);
	if (array != NULL)
		ft_bzero(array, nmemb * size);
	return (array);
}
