/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:49:36 by diomende          #+#    #+#             */
/*   Updated: 2025/06/27 15:48:15 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack b /
//  Do nothing if there is only one element or none.
void	swap_b (t_stack **stack_b)
{
	int		temp;
	int		idx;

	if (ft_lstsize (*stack_b) < 2)
		return ;

	temp = (*stack_b)->number;
	(*stack_b)->number = (*stack_b)->down->number;
	(*stack_b)->down->number = temp;

	idx = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->down->index;
	(*stack_b)->down->index = idx;

	write (1, "sb\n", 3);
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b (t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->down;
	(*stack_a)->up = NULL;
	if (!*stack_b)
	{
		*stack_b = node;
		(*stack_b)->up = NULL;
		(*stack_b)->down = NULL;
	}
	else
	{
		(*stack_b)->up = node;
		node->down = *stack_b;
		*stack_b = node;
	}
	write (1, "pb\n", 3);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b (t_stack **stack_b)
{
	t_stack *first_node;
	t_stack *last_node;

	if (!*stack_b)
		return ;
	if (ft_lstsize (*stack_b) < 2)
		return ;
	first_node = *stack_b;
	last_node = ft_lst_last(*stack_b);
	*stack_b = (*stack_b)->down;
	last_node->down = first_node;
	first_node->up = last_node;
	first_node->down = NULL;
	write (1, "rb\n", 3);
}

void	rotate_both (t_stack **stack_a, t_stack **stack_b)
{
	rotate_a (stack_a);
	rotate_b (stack_b);
	write (1, "rr\n", 3);
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	reverse_rotate_b (t_stack **stack_b)
{
	t_stack *first_node;
	t_stack *last_node;

	if (!*stack_b)
		return ;
	first_node = *stack_b;
	last_node = ft_lst_last(*stack_b);
	first_node->up = last_node;
	last_node->up->down = NULL;
	last_node->down = first_node;
	last_node->up = NULL;
	*stack_b = last_node;
	write (1, "rrb\n", 4);
}