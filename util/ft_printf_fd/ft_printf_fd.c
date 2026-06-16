/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:51:22 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 17:51:23 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

static size_t	pick_handler_fd(int fd, const char *fmt, va_list *args)
{
	if (*fmt == 'c')
		return (char_handler_fd(fd, args));
	else if (*fmt == 's')
		return (str_handler_fd(fd, args));
	else if (*fmt == 'p')
		return (ptr_handler_fd(fd, args));
	else if (*fmt == 'd' || *fmt == 'i')
		return (dec_handler_fd(fd, args));
	else if (*fmt == 'u')
		return (uint_handler_fd(fd, args));
	else if (*fmt == 'x')
		return (hex_handler_fd(fd, false, args));
	else if (*fmt == 'X')
		return (hex_handler_fd(fd, true, args));
	else if (*fmt == '%')
		return (write(fd, "%", 1));
	return (0);
}

int	ft_printf_fd(int fd, const char *fmt, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			count += write(fd, fmt++, 1);
			continue ;
		}
		fmt++;
		count += pick_handler_fd(fd, fmt, &args);
		fmt++;
	}
	va_end(args);
	return (count);
}
