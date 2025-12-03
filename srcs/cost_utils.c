/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:41 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:11:45 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate_both(t_stack **a, t_stack **b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b, 1);
		(*ca)--;
		(*cb)--;
	}
}

void	do_rev_rotate_both(t_stack **a, t_stack **b, int *ca, int *cb)
{
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b, 1);
		(*ca)++;
		(*cb)++;
	}
}

void	do_rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a != 0)
	{
		if (*cost_a > 0)
		{
			ra(a, 1);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra(a, 1);
			(*cost_a)++;
		}
	}
}

void	do_rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b != 0)
	{
		if (*cost_b > 0)
		{
			rb(b, 1);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb(b, 1);
			(*cost_b)++;
		}
	}
}
