/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:08 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:09 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = fill_stack(argc, argv);
	if (!stack_a)
		ft_error();
	if (!is_sorted(stack_a))
	{
		assign_index(stack_a, stack_size(stack_a));
		sort_stack(&stack_a);
	}
	free_stack(&stack_a);
	return (0);
}
