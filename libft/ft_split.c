/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:22:12 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/16 23:50:23 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

struct s_split_vars {
	char		**return_buffer;
	int			in_word;
	const char	*current_word;
	int			string_count;
	int			i;
	int			has_word;
};

static int	count_words(char const *str, char c)
{
	int	n;
	int	in_word;

	in_word = 0;
	n = 0;
	while (*str)
	{
		if (*str == c)
		{
			if (in_word)
				n++;
			in_word = 0;
		}
		else
			in_word = 1;
		str++;
	}
	if (in_word)
		n++;
	return (n);
}

static char	*ft_strrdup(char const *from, char const *to)
{
	char	*new_ptr;
	int		len;
	int		i;

	i = 0;
	while (from[i])
		i++;
	if (i > to - from)
		len = to - from;
	else
		len = i;
	new_ptr = ft_calloc(len + 1, sizeof(char));
	if (!new_ptr)
		return (NULL);
	while (len--)
		new_ptr[len] = from[len];
	return (new_ptr);
}

static void	initialize_variables(struct s_split_vars *v, const char *s, char c)
{
	v->i = 0;
	v->in_word = 0;
	v->string_count = count_words(s, c);
	v->return_buffer = ft_calloc(v->string_count + 1, sizeof(char *));
}

static void	check(struct s_split_vars *v)
{
	int		index;

	index = 0;
	while (index < v->string_count)
	{
		if (v->return_buffer[index] == NULL)
		{
			while (v->string_count--)
			{
				free(v->return_buffer[v->string_count]);
			}
			free(v->return_buffer);
			v->return_buffer = NULL;
			return ;
		}
		index++;
	}
}

char	**ft_split(char const *s, char c)
{
	struct s_split_vars	vars;

	initialize_variables(&vars, s, c);
	if (vars.return_buffer == NULL)
		return (NULL);
	while (vars.i < vars.string_count)
	{
		if (*s == c || *s == 0)
		{
			if (vars.in_word)
				vars.return_buffer[vars.i++] = ft_strrdup(vars.current_word, s);
			vars.in_word = 0;
		}
		else
		{
			if (!vars.in_word)
				vars.current_word = s;
			vars.in_word = 1;
		}
		s++;
	}
	check(&vars);
	return (vars.return_buffer);
}
