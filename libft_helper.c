/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:40:26 by diogo             #+#    #+#             */
/*   Updated: 2025/07/01 18:52:28 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a (stack_a);
	reverse_rotate_b (stack_b);
	write (1, "rrr\n", 4);
}

void	optimal_rotate(t_stack **stack_a, t_stack **stack_b, t_range data)
{
	push_b (stack_a, stack_b);
	if ((*stack_a)->index > data.max)
	{
		rotate_both (stack_a, stack_b);
		return ;
	}
	else
	{
		rotate_b (stack_b);
		return ;
	}
}
