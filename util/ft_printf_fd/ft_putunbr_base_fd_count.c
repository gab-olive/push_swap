/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd_count.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 00:00:00 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/08 00:00:00 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf_fd.h"

size_t	ft_putunbr_base_fd_count(int fd, unsigned long nbr, char *base)
{
	size_t		base_size;
	size_t		count;

	count = 0;
	base_size = ft_strlen(base);
	if (nbr >= base_size)
	{
		count += ft_putunbr_base_fd_count(fd, nbr / base_size, base);
		count += ft_putunbr_base_fd_count(fd, nbr % base_size, base);
	}
	else
	{
		count += ft_putchar_fd_count(fd, base[nbr]);
	}
	return (count);
}
