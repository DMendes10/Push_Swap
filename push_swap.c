/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:29 by diogo             #+#    #+#             */
/*   Updated: 2025/07/01 19:39:39 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack_a)
{
	t_stack	*ptr;

	ptr = stack_a;
	while (ptr->down)
	{
		if (ptr->number > ptr->down->number)
			return (0);
		ptr = ptr->down;
	}
	return (1);
}

int	optimal_divider(int size)
{
	int	divider;

	if (size > 400)
		divider = 30;
	else if (size >= 100)
		divider = 10;
	else if (size >= 50)
		divider = 5;
	else if (size >= 10)
		divider = size / 4;
	else
		divider = 4;
	return (divider);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
			write (2, "Error\n", 6);
			return (ft_lstclear (stack_a), ft_lstclear(stack_b), 0);
		}
	}
	if (check_sorted (stack_a))
		return (ft_lstclear (stack_a), ft_lstclear(stack_b), 0);
	i = optimal_divider (ft_lstsize (stack_a));
	choose_sort (&stack_a, &stack_b, i);
	return (ft_lstclear (stack_a), ft_lstclear(stack_b), 0);
}

// void print_value (t_stack *a, t_stack *b) // delete
// {
// 	printf("\nA\tB");
// 	printf("\n");
// 	while (a != NULL || b != NULL)
// 	{
// 		if (a)
// 		{
// 			printf("%d", (int)a->index);
// 			a = a->down;
// 		}
// 		else
// 			printf("   ");
// 		printf("\t   ");
// 		if (b)
// 		{
// 			printf("%d\n", (int)b->index);
// 			b = b->down;
// 		}
// 		else
// 			printf("\n");
// 	}
// 	printf("\n");
// 	printf("--------------------------------\n");
// 	fflush(stdout);
// }