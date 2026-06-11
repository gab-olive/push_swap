/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 00:00:00 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/08 00:00:00 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

size_t	char_handler_fd(int fd, va_list *args);
size_t	str_handler_fd(int fd, va_list *args);
size_t	ptr_handler_fd(int fd, va_list *args);
size_t	dec_handler_fd(int fd, va_list *args);
size_t	uint_handler_fd(int fd, va_list *args);
size_t	hex_handler_fd(int fd, int upper, va_list *args);
size_t	ft_putchar_fd_count(int fd, char c);
size_t	ft_putnbr_base_fd_count(int fd, long nbr, char *base);
size_t	ft_putunbr_base_fd_count(int fd, unsigned long nbr, char *base);
size_t	ft_putuint_base_fd_count(int fd, unsigned int nbr, char *base);
size_t	ft_putstr_fd_count(int fd, char *str);

int		ft_printf_fd(int fd, const char *fmt, ...);

#endif
