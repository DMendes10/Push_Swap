/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:58 by diogo             #+#    #+#             */
/*   Updated: 2025/06/17 18:26:29 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>


typedef struct s_list
{
	struct s_list	*up;
	struct s_list	*down;
	long			number;
}t_stack;

// typedef struct s_list
// {
// 	int		list_size;
// 	t_stack	*head;
// 	t_stack	*tail;
// }t_table;

// main

int	arg_checker (char *arg);

//list_utils
t_stack	*ft_lstnew(long content);
t_stack	*ft_lst_last(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *node);
void	ft_lstclear(t_stack *stack);
int		ft_lstsize(t_stack *lst);


//checker_utils
size_t	ft_count_words(const char *a, char c);
int		arg_validity(char *str);
int		double_check(t_stack *stack, long nbr);
int		ft_split_atoi(const char *arg, t_stack **stack);

// libft_helper
int		ft_isdigit(int c);



#endif