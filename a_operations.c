/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:10:15 by diomende          #+#    #+#             */
/*   Updated: 2025/06/20 17:36:39 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a /
//  Do nothing if there is only one element or none.
void	swap_a (t_stack **stack_a)
{
	int		temp;

	if (ft_lstsize (*stack_a) < 2)
		return ;
	temp = (*stack_a)->number;
	(*stack_a)->number = (*stack_a)->down->number;
	(*stack_a)->down->number = temp;

	write (1, "sa\n", 3);
}

// sa and sb at the same time.
void	swap_both (t_stack **stack_a, t_stack **stack_b)
{
	swap_a (stack_a);
	swap_b (stack_b);

	write (1, "ss\n", 3);
}

// Take the first element at the top of b and put it at the
//  top of a. Do nothing if b is empty.
void	push_a (t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->down;
	(*stack_b)->up = NULL;
	if (!*stack_a)
	{
		*stack_a = node;
		(*stack_a)->up = NULL;
		(*stack_a)->down = NULL;
	}
	else
	{
		(*stack_a)->up = node;
		node->down = *stack_a;
		*stack_a = node;
	}
	write (1, "pa\n", 3);
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a (t_stack **stack_a)
{
	t_stack *first_node;
	t_stack *last_node;

	if (!*stack_a)
		return ;
	first_node = *stack_a;
	last_node = ft_lst_last(*stack_a);
	*stack_a = (*stack_a)->down;
	last_node->down = first_node;
	first_node->up = last_node;
	first_node->down = NULL;
	write (1, "ra\n", 3);
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	reverse_rotate_a (t_stack **stack_a)
{
	t_stack *first_node;
	t_stack *last_node;

	if (!*stack_a)
		return ;
	first_node = *stack_a;
	last_node = ft_lst_last(*stack_a);
	first_node->up = last_node;
	last_node->up->down = NULL;
	last_node->down = first_node;
	last_node->up = NULL;
	*stack_a = last_node;
	write (1, "rra\n", 4);
}

