/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:52:18 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 15:01:59 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

size_t	ft_putuint_base_count(unsigned int nbr, char *base)
{
	size_t		base_size;
	size_t		count;

	count = 0;
	base_size = ft_strlen(base);
	if (nbr >= base_size)
	{
		count += ft_putuint_base_count(nbr / base_size, base);
		count += ft_putuint_base_count(nbr % base_size, base);
	}
	else
	{
		count += ft_putchar_count(base[nbr]);
	}
	return (count);
}
