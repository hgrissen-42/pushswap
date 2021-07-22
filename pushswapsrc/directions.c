#include "push_swap.h"

t_node	*find_node(t_stack *a_stack, int index)
{
	t_node	*current;

	current = a_stack->head;
	if (index < current->index)
	{
		while (index < current->previous->index
			&& current->index > current->previous->index)
			current = current->previous;
	}
	else
	{
		while (index > current->index
			&& current->index < current->next->index)
			current = current->next;
	}
	return (current);
}

void	ft_estimate_direction(t_stack *stack, int index, int *rx_size,
		int *rrx_size)
{
	t_node	*current;

	if (stack && stack->head)
	{
		current = stack->head;
		while (current->index != index)
		{
			(*rx_size)++;
			current = current->next;
		}
		current = stack->head;
		while (current->index != index)
		{
			(*rrx_size)++;
			current = current->previous;
		}
	}
}

void	ft_set_direction(int size, t_shift_info new_shift_info,
		t_shift_info *shift_info)
{
	if (!shift_info->is_set || size < shift_info->size)
	{
		shift_info->a_elem = new_shift_info.a_elem;
		shift_info->b_elem = new_shift_info.b_elem;
		shift_info->a_direction = new_shift_info.a_direction;
		shift_info->b_direction = new_shift_info.b_direction;
		shift_info->size = size;
		shift_info->is_set = true;
	}
}

void	ft_optimal_direction(t_stack *a_stack, t_stack *b_stack,
			t_node *b_elem, t_shift_info *shift_info)
{
	t_shift_info	new_shift_info;
	         int	ra_size;
	         int	rra_size;
	         int	rb_size;
	         int	rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	new_shift_info.a_elem = find_node(a_stack, b_elem->index);
	new_shift_info.b_elem = b_elem;
	ft_estimate_direction(a_stack, new_shift_info.a_elem->index,
		&ra_size, &rra_size);
	ft_estimate_direction(b_stack, b_elem->index,
		&rb_size, &rrb_size);
	new_shift_info.a_direction = R;
	new_shift_info.b_direction = R;
	ft_set_direction(ft_max(ra_size, rb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = RR;
	ft_set_direction(rra_size + rb_size, new_shift_info, shift_info);
	new_shift_info.b_direction = RR;
	ft_set_direction(ft_max(rra_size, rrb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = R;
	ft_set_direction(ra_size + rrb_size, new_shift_info, shift_info);
}

void	ft_opt_direction(t_stack *a_stack, t_stack *b_stack,
			t_shift_info *shift_info)
{
	         int	i;
	t_node	*current;

	if (b_stack)
	{
		i = 0;
		current = b_stack->head;
		while (i < b_stack->size)
		{
			ft_optimal_direction(a_stack, b_stack, current, shift_info);
			i++;
			current = current->next;
		}
	}
}
