/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:54:56 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 14:55:58 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdbool.h>

size_t	pick_handler(const char *fmt, va_list *args)
{
	if (*fmt == 'c')
		return (char_handler(args));
	else if (*fmt == 's')
		return (str_handler(args));
	else if (*fmt == 'p')
		return (ptr_handler(args));
	else if (*fmt == 'd' || *fmt == 'i')
		return (dec_handler(args));
	else if (*fmt == 'u')
		return (uint_handler(args));
	else if (*fmt == 'x')
		return (hex_handler(false, args));
	else if (*fmt == 'X')
		return (hex_handler(true, args));
	else if (*fmt == '%')
		return (write(STDOUT_FILENO, "%", 1));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			count += write(STDOUT_FILENO, fmt++, 1);
			continue ;
		}
		fmt++;
		count += pick_handler(fmt, &args);
		fmt++;
	}
	va_end(args);
	return (count);
}
