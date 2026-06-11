/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 00:00:00 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/08 00:00:00 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_fd.h"

size_t	char_handler_fd(int fd, va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	return (ft_putchar_fd_count(fd, c));
}
