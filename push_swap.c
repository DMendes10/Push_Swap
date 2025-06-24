/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:29 by diogo             #+#    #+#             */
/*   Updated: 2025/06/24 18:19:06 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_value (t_stack *a, t_stack *b) // delete
{
	printf("\nA\tB");
	printf("\n");
	while (a != NULL || b != NULL)
	{
		if (a)
		{
			printf("%d", (int)a->index);
			a = a->down;
		}
		else
			printf("   ");
		printf("\t   ");
		if (b)
		{
			printf("%d\n", (int)b->index);
			b = b->down;
		}
		else
			printf("\n");
	}
	printf("\n");
	printf("--------------------------------\n");
	fflush(stdout);
}

int	check_sorted (t_stack *stack_a)
{
	t_stack *ptr;
	
	ptr = stack_a;
	while (ptr->down)
	{
		if (ptr->number > ptr->down->number)
			return (0);
		ptr = ptr->down;
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
	if (check_sorted (stack_a))
		return (free(stack_a), free(stack_b), printf("sorted"), 0);
	choose_sort (&stack_a, &stack_b);
	print_value (stack_a, stack_b);
}

	
	
	
	
	
	
	
	// while (stack_a)
	// {
	// 	printf("stack a =%ld\n stack_a index = %ld\n", stack_a->number, stack_a->index);
	// 	stack_a = stack_a->down;
	// }
	
	// while (stack_b)
	// {
	// 	printf("stack b =%ld\n stack_b index = %ld\n", stack_b->number, stack_b->index);
	// 	stack_b = stack_b->down;
	// }
	// while (stack_b)
	// {
	// 	printf("stack b =%ld\n", stack_b->number);
	// 	stack_b = stack_b->down;
	// }

