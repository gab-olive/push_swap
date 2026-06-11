/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_handler_fd.c                                   :+:      :+:    :+:   */
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

size_t	ptr_handler_fd(int fd, va_list *args)
{
	void	*ptr;
	size_t	count;

	ptr = va_arg(*args, void *);
	if (ptr == 0x0)
	{
		count = ft_putstr_fd_count(fd, "(nil)");
		return (count);
	}
	count = ft_putstr_fd_count(fd, "0x");
	count += ft_putunbr_base_fd_count(fd, (unsigned long)ptr, "0123456789abcdef");
	return (count);
}
