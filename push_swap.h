/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:58 by diogo             #+#    #+#             */
/*   Updated: 2025/06/15 20:18:21 by diogo            ###   ########.fr       */
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
int ft_populate_lst (int argc, char **args, t_stack **stack_a);

//list_utils
t_stack	*ft_lstnew(long content);
t_stack	*ft_lst_last(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *node);
void	ft_lstclear(t_stack *stack);

//checker_utils
size_t	ft_count_words(const char *a, char c);
char	*ft_makestring(const char *s, char c);
void	ft_free(char **s);
char	**ft_minisplit(char **a, char const *s, char c);
char	**ft_split(char const *s, char c);

// checker_utils
int validity_check(t_stack *stack);
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);

// libft_helper
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);





#endif