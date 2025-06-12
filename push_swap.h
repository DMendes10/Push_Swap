#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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