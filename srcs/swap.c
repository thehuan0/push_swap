/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:46 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:47 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print)
		ft_putstr("sa\n");
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (print)
		ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b, int print)
{
	if (*a && (*a)->next)
		swap(a);
	if (*b && (*b)->next)
		swap(b);
	if (print && ((*a && (*a)->next) || (*b && (*b)->next)))
		ft_putstr("ss\n");
}
