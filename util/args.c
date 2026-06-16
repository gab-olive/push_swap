/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:37:21 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/16 12:20:47 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

int	add_number(struct s_args *args, int n)
{
	int	*new_ptr;
	int	i;

	if (args->size + 1 > args->cap)
	{
		args->cap = args->cap * 2;
		new_ptr = malloc(args->cap * sizeof(int));
		if (new_ptr == 0)
			return (0);
		i = 0;
		while (i < args->size)
		{
			new_ptr[i] = args->numbers[i];
			i++;
		}
		free(args->numbers);
		args->numbers = new_ptr;
	}
	args->numbers[args->size] = n;
	args->size++;
	return (1);
}

int	parse_flag(struct s_args *args, char *arg)
{
	if (ft_strncmp("--bench", arg, (size_t)(-1)) == 0)
		args->flags = args->flags | BENCH;
	else if (ft_strncmp("--simple", arg, (size_t)(-1)) == 0)
		args->flags = args->flags | SIMPLE;
	else if (ft_strncmp("--medium", arg, (size_t)(-1)) == 0)
		args->flags = args->flags | MEDIUM;
	else if (ft_strncmp("--complex", arg, (size_t)(-1)) == 0)
		args->flags = args->flags | COMPLEX;
	else if (ft_strncmp("--adaptive", arg, (size_t)(-1)) == 0)
		args->flags = args->flags | ADAPTIVE;
	else
		return (0);
	return (1);
}

int	validate_flags(struct s_args *args)
{
	int	flags;

	flags = args->flags;
	if (!!(flags & SIMPLE) + !!(flags & MEDIUM) + !!(flags & COMPLEX)
		+ !!(flags & ADAPTIVE) > 1)
		return (0);
	if (!!(flags & SIMPLE) + !!(flags & MEDIUM) + !!(flags & COMPLEX)
		+ !!(flags & ADAPTIVE) == 0)
		args->flags = args->flags | ADAPTIVE;
	return (1);
}

int	parse_args(struct s_args *args, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp("--", argv[i], (size_t)(2)) == 0)
		{
			if (!parse_flag(args, argv[i]))
				return (0);
		}
		else
			break ;
		i++;
	}
	if (!validate_flags(args))
		return (0);
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			return (0);
		add_number(args, ft_atoi(argv[i++]));
	}
	return (1);
}

int	initialize_args(struct s_args *args, int argc, char **argv)
{
	args->size = 0;
	args->cap = 1024;
	args->numbers = malloc(args->cap * sizeof(int));
	if (args->numbers == NULL)
		return (0);
	args->flags = 0;
	return (parse_args(args, argc, argv));
}
