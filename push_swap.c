/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:29 by diogo             #+#    #+#             */
/*   Updated: 2025/06/15 20:26:48 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checka se os args passados sao validos (sao numeros)
int	arg_checker (char *arg)
{
	int	i;
	int j;
	char **splited_args;

	i = 0;
	if (ft_count_words (arg, ' ') > 1)
	{
		splited_args = ft_split(arg, ' ');
		while (splited_args[i])
		{
			j = 0;
			while (splited_args[i][j])
				if (ft_isdigit(splited_args[i][j++]) == 0)
					return (0);
			i++;
		}
		free (splited_args);
	}
	else
	{
		while (arg[i])
			if (ft_isdigit(arg[i++]) == 0)
				return (0);
	}
	return (1);
}

// funcao que pega nos argumentos e mete-os todos numa lista..
// tambem verifica cada vez que poe um nmr se esse nmr ja esta na lista
// se ja estiver retorna error
int ft_populate_lst (int argc, char **args, t_stack **stack_a)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		// if (ft_count_words(args[i], ' ') > 1)
		// {
		// 	ft_atoi_split 
		// 	i++;
		// }
		// else
		// {
			ft_lstadd_back (stack_a, ft_lstnew (ft_atoi(args[i])));
			if (validity_check (*stack_a) == 1)
				return(ft_lstclear(*stack_a), 0);
			i++;
		// }
	}
	return (1);
}


int main (int ac, char **av)
{
	int	i;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 1;
	stack_a = NULL;
	if (ac < 3)
		if (ft_count_words (av[1], ' ') < 2)
			return (0);
	while (i < ac)
		if (arg_checker(av[i++]) == 0)
			return(write(2,"Error\n", 7));
	if (ft_populate_lst (ac, av, &stack_a) != 1)
		return(write(2,"Error\n", 7));
	// while (stack_a)
	// 		{
	// 			printf("%d\n", stack_a->number);
	// 			stack_a = stack_a->up;
	// 		}
}
