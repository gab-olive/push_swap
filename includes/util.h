/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:28:05 by zleullie          #+#    #+#             */
/*   Updated: 2026/06/09 14:21:43 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "push_swap.h"

enum	e_flags
{
	BENCH = 1 << 0,
	SIMPLE = 1 << 1,
	MEDIUM = 1 << 2,
	COMPLEX = 1 << 3,
	ADAPTIVE = 1 << 4
};

struct	s_args
{
	int	*numbers;
	int	size;
	int	cap;
	int	flags;
};

int		add_number(struct s_args *args, int n);
int		ft_is_number(const char *str);
int		parse_flag(struct s_args *args, char *arg);
int		validate_flags(struct s_args *args);
int		parse_args(struct s_args *args, int argc, char **argv);
int		initialize_args(struct s_args *args, int argc, char **argv);
t_node	*push_back(t_stack *stack, int value);
void	min_sort(t_stack *a, t_stack *b);
void	index_stack(t_stack *a);
int		get_max_bits(t_stack *stack);
void	radix_sort(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	swap(t_stack *s);
void	sa(t_stack *a);
void	sb(t_stack *b);
int		stack_from_list(struct s_args *args, t_stack *a);
void	stack_init(t_stack *stack);
void	stack_clear(t_stack *stack);
void	print_stack(t_stack *stack, char *name);
t_node	*create_node(int value);
int		int_sqrt(int n);
void	count_operation(int op);
int		get_operation_count(int op);
double	compute_disorder(int *numbers, size_t size);
void	chunk_sort(t_stack *a, t_stack *b);
void	bench(struct s_args *args);
int		get_total_operations(void);
int		ft_printf_fd(int fd, const char *fmt, ...);
void	sort_three(t_stack *a);
int		is_sorted(t_stack *a);
void	quick_sort(t_stack *a, t_stack *b);
void	sort_three_top(t_stack *a, t_stack *b, int n);
int		get_median(t_stack *a, int top_n);
void	quick_sortA(t_stack *a, t_stack *b, int n);
void	quick_sortB(t_stack *a, t_stack *b, int n);

#endif