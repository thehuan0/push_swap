/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:22 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:23 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print)
		ft_putstr("ra\n");
}

void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print)
		ft_putstr("rb\n");
}

void	rr(t_stack **a, t_stack **b, int print)
{
	if (*a && (*a)->next)
		rotate(a);
	if (*b && (*b)->next)
		rotate(b);
	if (print && ((*a && (*a)->next) || (*b && (*b)->next)))
		ft_putstr("rr\n");
}
