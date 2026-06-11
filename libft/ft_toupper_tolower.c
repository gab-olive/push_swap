/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_tolower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:00:56 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 01:21:15 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
