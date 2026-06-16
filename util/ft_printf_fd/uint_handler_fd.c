/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_handler_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:52:20 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 17:52:20 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_fd.h"

size_t	uint_handler_fd(int fd, va_list *args)
{
	unsigned int	nbr;
	size_t			count;

	nbr = va_arg(*args, unsigned int);
	count = ft_putunbr_base_fd_count(fd, nbr, "0123456789");
	return (count);
}
