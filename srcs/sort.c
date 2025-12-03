/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:36 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:37 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b, 1);
			pushed++;
		}
		else
			ra(a, 1);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b, 1);
		pushed++;
	}
}

static int	find_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

static int	find_min_position(t_stack *stack, int min_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == min_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	shift_stack(t_stack **stack_a)
{
	int	min_index;
	int	min_pos;
	int	size;

	min_index = find_min_index(*stack_a);
	size = stack_size(*stack_a);
	min_pos = find_min_position(*stack_a, min_index);
	if (min_pos > size / 2)
	{
		while ((*stack_a)->index != min_index)
			rra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->index != min_index)
			ra(stack_a, 1);
	}
}
