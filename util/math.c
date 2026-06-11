/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:52:43 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/06 19:21:03 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// a * a <= b <--> a * a / a <= b / a <--> a <= b / a
int	int_sqrt(int n)
{
	int	root;

	if (n <= 0)
		return (0);
	root = 1;
	while (root <= n / root)
	{
		root++;
	}
	return (root - 1);
}
