/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:27:54 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/05 15:29:29 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_number(const char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}
