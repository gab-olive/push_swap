/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:46:02 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 14:54:23 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

size_t	dec_handler(va_list *args)
{
	int	nbr;

	nbr = va_arg(*args, int);
	return (ft_putnbr_base_count(nbr, "0123456789"));
}
