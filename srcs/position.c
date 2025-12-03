/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:11 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:12 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;

	tmp = *stack;
	pos = 0;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}

static int	get_lowest_index_pos(t_stack **a)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *a;
	lowest_index = INT_MAX;
	get_position(a);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static int	get_target(t_stack **a, int index_b)
{
	t_stack	*tmp;
	int		target_index;
	int		target_pos;

	tmp = *a;
	target_index = INT_MAX;
	target_pos = -1;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	return (get_lowest_index_pos(a));
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	get_position(a);
	get_position(b);
	while (tmp)
	{
		tmp->target_pos = get_target(a, tmp->index);
		tmp = tmp->next;
	}
}
