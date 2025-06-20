/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:59:27 by diomende          #+#    #+#             */
/*   Updated: 2025/06/20 19:18:18 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort (t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = ft_lstsize (*stack_a);
	if (size == 2)
		return (swap_a (stack_a));
	else if (size == 3)
		sort_three(stack_a);
	// else if (size == 5)
	// 	sort_five(stack_a, stack_b);
}

void	sort_three (t_stack **stack)
{
	t_stack *last;
	int	second;
	int	third;
	
	last = ft_lst_last (*stack);
	if ((*stack)->number > (*stack)->down->number)
		swap_a(stack);
	second = (*stack)->down->number;
	third = last->number;
	if (third < second && third < (*stack)->number)
		reverse_rotate_a (stack);
	else if (third < second)
	{
		reverse_rotate_a (stack);
		swap_a(stack);
	}
}