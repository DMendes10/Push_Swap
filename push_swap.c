#include "push_swap.h"

int	arg_checker (char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (NULL);
	while (arg[i])
}

int main (int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 2)
	{
		while (av[i++])
			if (arg_checker(av[i]) == 0)
				return (write(1,"Error\n", 7));
	}
}
