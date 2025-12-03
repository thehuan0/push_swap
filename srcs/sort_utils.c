/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:33 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:34 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	min = INT_MAX;
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min_pos;

	if (!*a || is_sorted(*a))
		return ;
	min_pos = get_min_index_pos(*a);
	if (min_pos == 1)
		ra(a, 1);
	else if (min_pos == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (min_pos == 3)
		rra(a, 1);
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	distance;

	if (!*a || is_sorted(*a))
		return ;
	distance = get_min_index_pos(*a);
	if (distance == 1)
		ra(a, 1);
	else if (distance == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (distance == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (distance == 4)
		rra(a, 1);
	if (!is_sorted(*a))
	{
		pb(a, b, 1);
		sort_four(a, b);
		pa(a, b, 1);
	}
}
