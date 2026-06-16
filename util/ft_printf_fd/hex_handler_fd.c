/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:51:56 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 17:51:57 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_fd.h"

size_t	hex_handler_fd(int fd, int upper, va_list *args)
{
	int		nbr;
	char	*base;
	size_t	count;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	nbr = va_arg(*args, unsigned int);
	count = ft_putuint_base_fd_count(fd, nbr, base);
	return (count);
}
