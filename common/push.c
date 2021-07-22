#include "push_swap.h"

void	ft_push(t_stack *stack, t_node *node)
{
	t_node	*tail;

	if (stack && node)
	{
		if (!stack->head)
		{
			stack->head = node;
			stack->head->previous = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			node->previous = tail;
			tail->next = node;
			node->next = stack->head;
			stack->head->previous = node;
			stack->head = node;
		}
		stack->size++;
	}
}

t_node	*ft_pop(t_stack *stack)
{
	t_node	*node;

	node = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			node = stack->head;
			stack->head = NULL;
			node->previous = NULL;
			node->next = NULL;
		}
		else
		{
			node = stack->head;
			stack->head = stack->head->next;
			node->previous->next = node->next;
			node->next->previous = node->previous;
			node->previous = NULL;
			node->next = NULL;
		}
		stack->size--;
	}
	return (node);
}

void	ft_px(t_stack *to, t_stack *from, const char *name)
{
	ft_push(to, ft_pop(from));
	if (name)
		ft_putendl(name);
}
