/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:56:28 by diogo             #+#    #+#             */
/*   Updated: 2025/06/15 20:37:43 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if the last number added to the list already exists in the list 
// and also if its a valid int. if any of those is true it returns 1 and displays error
int validity_check(t_stack *stack)
{
    t_stack *last;
    long nbr;
    
    last = ft_lst_last(stack);
    nbr = last->number;
    last = last->down;
    while (last)
    {
        if (nbr > 2147483647 || nbr < -2147483648 || nbr == last->number)
            return (1);
        last = last->down;
    }
    return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	sign;
	int				result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}