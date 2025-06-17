/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:29 by diogo             #+#    #+#             */
/*   Updated: 2025/06/17 19:09:14 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted (t_stack *stack_a, t_stack *stack_b)
{
	t_stack *ptr;
	
	if (stack_b)
		return (0);
	ptr = stack_a;
	while (ptr->up)
	{
		if (ptr->number > ptr->up->number)
			return (0);
		ptr = ptr->up;
	}
	return (1);
}

int main (int ac, char **av)
{
	int	i;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 3)
		if (ft_count_words (av[1], ' ') < 2)
			return (0);
	while (++i < ac)
	{
		if (!arg_validity(av[i]) || !ft_split_atoi (av[i], &stack_a))
		{
			write(2,"Error\n", 6);
			return (free(stack_a), free(stack_b), 0);
		}
	}
	if (check_sorted (stack_a, stack_b))
		return (free(stack_a), free(stack_b), printf("sorted"), 0);
	
	while (stack_a)
	{
		printf("%ld\n", stack_a->number);
		stack_a = stack_a->up;
	}
}
