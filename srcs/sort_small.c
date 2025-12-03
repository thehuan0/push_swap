/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:30 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:31 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_stack **stack)
{
	int	max;

	if (!*stack || is_sorted(*stack))
		return ;
	max = get_max_index(*stack);
	if ((*stack)->index == max)
		ra(stack, 1);
	else if ((*stack)->next->index == max)
		rra(stack, 1);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack, 1);
}
