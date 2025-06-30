/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:25:55 by diomende          #+#    #+#             */
/*   Updated: 2025/06/30 16:35:12 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_decider(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size < 2)
		push_a (stack_a, stack_b);
	else if (push_cost (*stack_b, size) <= push_cost (*stack_b, size - 1))
	{
		if (top_cost (*stack_b, size) < bottom_cost(*stack_b, size))
			push_b_up (stack_a, stack_b, size);
		else
			push_b_down (stack_a, stack_b, size);
		if (top_cost (*stack_b, size - 1) < bottom_cost(*stack_b, size - 1))
			push_b_up (stack_a, stack_b, size - 1);
		else
			push_b_down (stack_a, stack_b, size - 1);
	}
	else
	{
		if (top_cost (*stack_b, size - 1) < bottom_cost(*stack_b, size - 1))
			push_b_up (stack_a, stack_b, size - 1);
		else
			push_b_down (stack_a, stack_b, size - 1);
		if (top_cost (*stack_b, size) < bottom_cost(*stack_b, size))
			push_b_up_alt (stack_a, stack_b, size);
		else
			push_b_down_alt (stack_a, stack_b, size);
	}
}

int	push_cost(t_stack *stack_b, int idx)
{
	int	cost_top;
	int	cost_bottom;

	cost_top = top_cost (stack_b, idx);
	cost_bottom = bottom_cost (stack_b, idx);
	if (cost_top < cost_bottom)
		return (cost_top);
	return (cost_bottom);
}

int	top_cost(t_stack *stack_b, int idx)
{
	t_stack	*top;
	int		cost_top;

	top = stack_b;
	cost_top = 0;
	while (top->down)
	{
		if (top->index == idx)
			break ;
		cost_top++;
		top = top->down;
	}
	return (cost_top);
}

int	bottom_cost(t_stack *stack_b, int idx)
{
	t_stack	*bottom;
	int		cost_bottom;

	cost_bottom = 1;
	bottom = ft_lst_last (stack_b);
	while (bottom->up)
	{
		if (bottom->index == idx)
			break ;
		cost_bottom++;
		bottom = bottom->up;
	}
	return (cost_bottom);
}
