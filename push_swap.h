/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:58 by diogo             #+#    #+#             */
/*   Updated: 2025/06/30 16:31:16 by diomende         ###   ########.fr       */
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

// # define SUCCESS 1
// # define FAILED 0

typedef struct s_list
{
	struct s_list	*up;
	struct s_list	*down;
	long			number;
	long			index;
}	t_stack;

typedef struct s_range
{
	int		min;
	int		max;
	int		count_limit;
}	t_range;

// main
int		check_sorted(t_stack *stack_a);
int		optimal_divider(int size);

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
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

// a_operations
void	swap_a(t_stack **stack_a);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	reverse_rotate_a(t_stack **stack_a);

// b_operations
void	swap_b(t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_b(t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_b(t_stack **stack_b);

// sorting_utils
void	choose_sort(t_stack **stack_a, t_stack **stack_b, int divider);
void	sort_three(t_stack **stack);
void	normalize_stack(t_stack **stack_a, int size);
void	sort_b(t_stack **stack_a, t_stack **stack_b, t_range data);
void	normalize_and_push(t_stack **stack_a, t_stack **stack_b, int size, \
	int divider);

// sorting_b
void	push_b_down(t_stack **stack_a, t_stack **stack_b, int idx);
void	push_b_up(t_stack **stack_a, t_stack **stack_b, int idx);
void	push_b_down_alt(t_stack **stack_a, t_stack **stack_b, int idx);
void	push_b_up_alt(t_stack **stack_a, t_stack **stack_b, int idx);
void	organize_four(t_stack **stack_a, t_stack **stack_b, int size);

// sorting_part2
void	push_decider(t_stack **stack_a, t_stack **stack_b, int size);
int		push_cost(t_stack *stack_b, int idx);
int		top_cost(t_stack *stack_b, int idx);
int		bottom_cost(t_stack *stack_b, int idx);

// void print_value (t_stack *a, t_stack *b);

#endif