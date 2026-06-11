/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:46:02 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 14:52:53 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

size_t	ptr_handler(va_list *args)
{
	void	*ptr;
	size_t	count;

	ptr = va_arg(*args, void *);
	if (ptr == 0x0)
	{
		count = ft_putstr_count("(nil)");
		return (count);
	}
	count = ft_putstr_count("0x");
	count += ft_putunbr_base_count((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
