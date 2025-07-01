/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:59:27 by diomende          #+#    #+#             */
/*   Updated: 2025/07/01 18:40:35 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_stack **stack_a, t_stack **stack_b, int divider)
{
	int		size;

	size = ft_lstsize (*stack_a);
	if (size == 2)
		return (swap_a (stack_a));
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		organize_four(stack_a, stack_b);
	else
	{
		normalize_and_push (stack_a, stack_b, size, divider);
		if (!check_sorted(*stack_a))
			sort_three(stack_a);
		while (ft_lstsize (*stack_b) > 0)
			push_decider (stack_a, stack_b, ft_lstsize (*stack_b));
	}
}

void	normalize_stack(t_stack **stack_a, int size)
{
	int		counter;
	int		idx;
	t_stack	*smallest;
	t_stack	*stack;

	counter = 0;
	idx = 1;
	while (counter < size)
	{
		stack = *stack_a;
		while (stack->index != 0)
			stack = stack->down;
		smallest = stack;
		stack = *stack_a;
		while (stack)
		{
			if (stack->number < smallest->number && stack->index == 0)
				smallest = stack;
			stack = stack->down;
		}
		smallest->index = idx;
		idx++;
		counter++;
	}
}

void	sort_b(t_stack **stack_a, t_stack **stack_b, t_range data)
{
	int	count;

	count = 0;
	while (ft_lstsize (*stack_a) > 3 && count < (data.max - data.min) * 2)
	{
		if ((*stack_a)->index < data.min && (*stack_a)->index < \
		data.count_limit)
		{
			optimal_rotate (stack_a, stack_b, data);
			count++;
		}
		else if ((*stack_a)->index <= data.max && (*stack_a)->index \
		< data.count_limit)
		{
			push_b (stack_a, stack_b);
			count++;
		}
		else
			rotate_a (stack_a);
	}
}

void	sort_three(t_stack **stack)
{
	t_stack	*last;
	int		second;
	int		third;

	last = ft_lst_last (*stack);
	if ((*stack)->number > (*stack)->down->number)
		swap_a (stack);
	second = (*stack)->down->number;
	third = last->number;
	if (third < second && third < (*stack)->number)
		reverse_rotate_a (stack);
	else if (third < second)
	{
		reverse_rotate_a (stack);
		swap_a (stack);
	}
}

void	normalize_and_push(t_stack **stack_a, t_stack **stack_b, int size, \
	int divider)
{
	t_range	data;

	normalize_stack (stack_a, size);
	data.min = divider;
	data.max = data.min * 2;
	data.count_limit = size - 2;
	while (ft_lstsize (*stack_a) > 3)
	{
		sort_b (stack_a, stack_b, data);
		data.min += (divider * 2);
		data.max += (divider * 2);
	}
}
