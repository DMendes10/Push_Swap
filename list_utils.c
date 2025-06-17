/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:04:41 by diogo             #+#    #+#             */
/*   Updated: 2025/06/17 15:18:39 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(long content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = content;
	node->up = NULL;
    node->down = NULL;
	return (node);
}

t_stack	*ft_lst_last(t_stack *stack)
{
	t_stack	*ptr;

	
	ptr = stack;
	while (ptr->up)
	{
		ptr = ptr->up;
	}
	return (ptr);
}

void	ft_lstadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!node || !stack)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	else
	{
		last = ft_lst_last(*stack);
		last->up = node;
		node->down = last;
	}
}

void	ft_lstclear(t_stack *stack)
{
	t_stack	*ptr;

	if (!stack)
		return ;
	ptr = stack;
    while (ptr)
	{
		stack = stack->up;
		free (ptr);
		ptr = stack;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->up;
		i++;
	}
	return (i);
}