/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:52:08 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 17:52:09 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_fd.h"

size_t	str_handler_fd(int fd, va_list *args)
{
	char	*c;
	size_t	count;

	c = va_arg(*args, char *);
	if (c == 0x0)
		count = ft_putstr_fd_count(fd, "(null)");
	else
		count = ft_putstr_fd_count(fd, c);
	return (count);
}
