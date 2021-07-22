#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc >= 2)
	{
		stack = create_stack(argv);
		indexing(stack);
		markup_stack(stack);
		solve(stack);
		free_stack(stack);
	}
	return (0);
}
