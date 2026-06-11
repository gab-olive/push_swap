/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:26:22 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 23:09:26 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static void	ft_partial_itoa(int n, char *str)
{
	long	nbr;
	char	s[2];

	nbr = n;
	if (n < 0)
	{
		ft_strlcat(str, "-", 32);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_partial_itoa(nbr / 10, str);
		ft_partial_itoa(nbr % 10, str);
	}
	else
	{
		ft_bzero(s, 2);
		s[0] = nbr + '0';
		ft_strlcat(str, s, 32);
	}
}

char	*ft_itoa(int n)
{
	char	*buf;
	char	*str;

	buf = malloc(32);
	if (!buf)
		return (NULL);
	ft_bzero(buf, 32);
	ft_partial_itoa(n, buf);
	str = ft_strdup(buf);
	free(buf);
	if (!str)
		return (NULL);
	return (str);
}
