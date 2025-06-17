/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:56:28 by diogo             #+#    #+#             */
/*   Updated: 2025/06/17 18:27:49 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if the last number added to the list already exists in the list 
// at the begining the list has not been initialized so we check for that
int double_check(t_stack *stack, long nbr)
{
    t_stack *last;
	
	if (ft_lstsize (stack) < 1)
		return (1);
    last = ft_lst_last(stack);
    while (last)
    {
        if (nbr == last->number)
            return (0);
        last = last->down;
    }
    return (1);
}

int	ft_split_atoi(const char *arg, t_stack **stack)
{
	unsigned int	i;
	int				sign;
	long			result;

	i = 0;
	while (arg[i])
	{
		result = 0;
		sign = 1;
		while (arg[i] == ' ')
			i++;
		if (arg[i] == '-' || arg[i] == '+')
			if (arg[i++] == '-')
				sign *= -1;
		while (ft_isdigit(arg[i]) == 1)
			result = (result * 10) + (arg[i++] - 48);
		result *= sign;
		if (result > 2147483647 || result < -2147483648 || !double_check(*stack, result))
			return (0);
		ft_lstadd_back (stack, ft_lstnew(result));
	}
	return (1);
}

size_t	ft_count_words(const char *a, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (!a)
		return (0);
	while (a[i])
	{
		while (a[i] == c)
			i++;
		if (a[i])
			count++;
		while (a[i] && a[i] != c)
			i++;
	}
	return (count);
}

int	arg_validity(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && \
			str[i - 1] == ' ' && ft_isdigit(str[i + 1]))
			i++;
		else if (ft_isdigit(str[i]) || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
