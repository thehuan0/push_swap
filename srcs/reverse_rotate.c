/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:19 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:20 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print)
		ft_putstr("rra\n");
}

void	rrb(t_stack **b, int print)
{
	reverse_rotate(b);
	if (print)
		ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	if (*a && (*a)->next)
		reverse_rotate(a);
	if (*b && (*b)->next)
		reverse_rotate(b);
	if (print && ((*a && (*a)->next) || (*b && (*b)->next)))
		ft_putstr("rrr\n");
}
