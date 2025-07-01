NAME = push_swap

SRCS = a_operations.c b_operations.c checker_utils.c libft_helper.c list_utils.c \
	push_swap.c sorting_b.c sorting_part2.c sorting_utils.c

OBJS = a_operations.o b_operations.o checker_utils.o libft_helper.o list_utils.o \
	push_swap.o sorting_b.o sorting_part2.o sorting_utils.o

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re