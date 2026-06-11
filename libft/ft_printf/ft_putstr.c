/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:07:02 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 14:53:35 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_putstr_count(char *str)
{
	size_t	strlen;

	strlen = ft_strlen(str);
	return (write(STDOUT_FILENO, str, strlen));
}
