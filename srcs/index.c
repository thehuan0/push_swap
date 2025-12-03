/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:05 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:06 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if (stack->index == -1 && (!min || stack->value < min->value))
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	assign_index(t_stack *stack_a, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_a;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	i = 0;
	while (i < size)
	{
		tmp = get_min(stack_a);
		tmp->index = i;
		i++;
	}
}
