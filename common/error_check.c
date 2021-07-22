#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	int				i;
	t_node	*current;
	t_node	*delete;

	if (stack != NULL)
	{
		i = 0;
		current = stack->head;
		while (i < stack->size)
		{
			delete = current;
			current = current->next;
			free(delete);
			i++;
		}
		free(stack);
	}
}

void	ft_error(void)
{
	ft_putendl("Error");
	exit(EXIT_FAILURE);
}

void	check_duplicates(t_stack *stack)
{
	         int	i;
	t_node	*current_i;
	t_node	*current_j;

	i = 0;
	current_i = stack->head;
	while (i < stack->size)
	{
		current_j = current_i->next;
		while (current_j != current_i)
		{
			if (current_i->number == current_j->number)
				ft_error();
			current_j = current_j->next;
		}
		i++;
		current_i = current_i->next;
	}
}
