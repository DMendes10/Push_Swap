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
	int				number;
}t_list;

typedef struct s_list
{
	int		list_size;
	t_list	*head;
	t_list	*tail;
}t_table;

#endif