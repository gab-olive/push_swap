/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:31:12 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 14:52:11 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

size_t	char_handler(va_list *args);
size_t	str_handler(va_list *args);
size_t	ptr_handler(va_list *args);
size_t	dec_handler(va_list *args);
size_t	uint_handler(va_list *args);
size_t	hex_handler(int upper, va_list *args);
size_t	ft_putchar_count(char c);
size_t	ft_putnbr_base_count(long nbr, char *base);
size_t	ft_putunbr_base_count(unsigned long nbr, char *base);
size_t	ft_putuint_base_count(unsigned int nbr, char *base);
size_t	ft_putstr_count(char *str);

#endif