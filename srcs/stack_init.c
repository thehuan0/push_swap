/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:39 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/03 23:16:49 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;
	int	non_zero_digits;

	i = 0;
	non_zero_digits = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		non_zero_digits++;
		i++;
	}
	if (str[i])
		return (0);
	if (non_zero_digits > 10)
		return (0);
	return (1);
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	has_duplicates(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	process_split(char **nums, t_stack **stack)
{
	int		i;
	long	num;

	i = 0;
	while (nums[i])
	{
		if (!is_valid_number(nums[i]))
			return (0);
		num = ft_atol(nums[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		if (has_duplicates(*stack, (int)num))
			return (0);
		add_back(stack, create_node((int)num));
		if (!*stack)
			return (0);
		i++;
	}
	return (1);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	char	**nums;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strchr_ps(argv[i], ' '))
		{
			nums = ft_split(argv[i], ' ');
			if (!nums || !process_split(nums, &stack))
				return (free_split(nums), free_stack(&stack), NULL);
			free_split(nums);
		}
		else
		{
			if (!is_valid_number(argv[i]))
				return (free_stack(&stack), NULL);
			if (!add_number(argv[i], &stack))
				return (free_stack(&stack), NULL);
		}
		i++;
	}
	return (stack);
}
