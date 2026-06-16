/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_handler_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:51:16 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 17:51:17 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_fd.h"

size_t	dec_handler_fd(int fd, va_list *args)
{
	int	nbr;

	nbr = va_arg(*args, int);
	return (ft_putnbr_base_fd_count(fd, nbr, "0123456789"));
}
