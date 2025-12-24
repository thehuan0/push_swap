/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:08 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/24 19:50:49 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static void	execute_instruction_2(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, 0);
	else
	{
		free(line);
		ft_error();
	}
}

static void	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, 0);
	else
		execute_instruction_2(line, a, b);
}

static void	read_and_execute(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = fill_stack(argc, argv);
	if (!a)
		ft_error();
	b = NULL;
	read_and_execute(&a, &b);
	if (is_sorted(a) && !b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
