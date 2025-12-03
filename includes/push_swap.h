/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:07:17 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/03 12:07:22 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// Stack operations
t_stack	*create_node(int value);
void	add_back(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);
int		add_number(char *str, t_stack **stack);

// Stack initialization
int		is_valid_number(char *str);
long	ft_atol(char *str);
int		has_duplicates(t_stack *stack, int value);
t_stack	*fill_stack(int argc, char **argv);

// Utils
void	ft_putstr(char *str);
void	ft_error(void);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
int		ft_strchr_ps(const char *s, int c);
char	**ft_split(char const *s, char c);
void	free_split(char **str);
int		ft_strcmp(const char *s1, const char *s2);

// Atoi
int		ft_atoi(const char *str);

// Operations
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

// Sorting
void	assign_index(t_stack *stack_a, int size);
void	get_position(t_stack **stack);
void	get_target_position(t_stack **a, t_stack **b);
void	get_cost(t_stack **a, t_stack **b);
void	do_cheapest_move(t_stack **a, t_stack **b);
void	sort_stack(t_stack **stack_a);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int		get_min_index_pos(t_stack *stack);
void	push_to_b(t_stack **a, t_stack **b);
void	shift_stack(t_stack **stack_a);

// Cost utils
void	do_rotate_both(t_stack **a, t_stack **b, int *ca, int *cb);
void	do_rev_rotate_both(t_stack **a, t_stack **b, int *ca, int *cb);
void	do_rotate_a(t_stack **a, int *cost_a);
void	do_rotate_b(t_stack **b, int *cost_b);

#endif
