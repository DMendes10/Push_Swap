/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:02:26 by diomende          #+#    #+#             */
/*   Updated: 2025/06/30 16:33:21 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_down(t_stack **stack_a, t_stack **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
			return (push_a(stack_a, stack_b));
		else
			reverse_rotate_b(stack_b);
	}
}

void	push_b_up(t_stack **stack_a, t_stack **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
			return (push_a(stack_a, stack_b));
		else
			rotate_b(stack_b);
	}
}

void	push_b_down_alt(t_stack **stack_a, t_stack **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
		{
			push_a (stack_a, stack_b);
			swap_a (stack_a);
			return ;
		}
		else
			reverse_rotate_b(stack_b);
	}
}

void	push_b_up_alt(t_stack **stack_a, t_stack **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
		{
			push_a (stack_a, stack_b);
			swap_a (stack_a);
			return ;
		}
		else
			rotate_b (stack_b);
	}
}

void	organize_four(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	cost_top;
	int	cost_bottom;

	normalize_stack (stack_a, 4);
	while (*stack_a)
	{
		if ((*stack_a)->index == 1)
		{
			push_b (stack_a, stack_b);
			break ;
		}
		else
			rotate_a (stack_a);
	}
	if (!check_sorted (*stack_a))
		sort_three (stack_a);
	push_a (stack_a, stack_b);
}
