/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_count.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 00:00:00 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/08 00:00:00 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "ft_printf_fd.h"

static size_t	ft_putnbr_fd_helper(int fd, long nbr, char *base, long base_size)
{
	size_t	count;

	count = 0;
	if (nbr <= -base_size)
	{
		count += ft_putnbr_fd_helper(fd, nbr / base_size, base, base_size);
		count += ft_putnbr_fd_helper(fd, nbr % base_size, base, base_size);
	}
	else
	{
		count += ft_putchar_fd_count(fd, base[-nbr]);
	}
	return (count);
}

size_t	ft_putnbr_base_fd_count(int fd, long nbr, char *base)
{
	size_t		base_size;
	size_t		count;

	base_size = ft_strlen(base);
	if (base_size > LONG_MAX)
		return (0);
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar_fd_count(fd, '-');
	}
	else
	{
		nbr = -nbr;
	}
	return (count + ft_putnbr_fd_helper(fd, nbr, base, (long)base_size));
}
