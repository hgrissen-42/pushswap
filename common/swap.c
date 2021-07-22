#include "push_swap.h"

void	swap(t_node *first, t_node *second, t_stack *stack)
{
	t_node	*previous;
	t_node	*next;

	previous = first->previous;
	next = second->next;
	previous->next = second;
	second->previous = previous;
	first->next = next;
	next->previous = first;
	second->next = first;
	first->previous = second;
	stack->head = second;
}

void	ft_sx(t_stack *stack, const char *name)
{
	if (stack && stack->head && stack->size >= 2)
		swap(stack->head, stack->head->next, stack);
	if (name)
		ft_putendl(name);
}

void	ft_ss(t_stack *a, t_stack *b, const char *name)
{
	ft_sx(a, NULL);
	ft_sx(b, NULL);
	if (name)
		ft_putendl(name);
}
