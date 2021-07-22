#include "push_swap.h"

void	ft_omkltom(t_stack *a_stack, t_stack *b_stack, t_shift_info *shift_info)
{
	if (shift_info->a_direction == R)
		ft_rr(a_stack, b_stack, "rr");
	else
		ft_rrr(a_stack, b_stack, "rrr");
}

void	ft_move_b(t_stack *a_stack, t_stack *b_stack, t_shift_info *shift_info)
{
	while (shift_info->a_elem != a_stack->head
		|| shift_info->b_elem != b_stack->head)
	{
		if (shift_info->a_direction == shift_info->b_direction
			&& shift_info->a_elem != a_stack->head
			&& shift_info->b_elem != b_stack->head)
			ft_omkltom(a_stack, b_stack, shift_info);
		else if (shift_info->a_elem != a_stack->head)
		{
			if (shift_info->a_direction == R)
				ft_rx(a_stack, "ra");
			else
				ft_rrx(a_stack, "rra");
		}
		else if (shift_info->b_elem != b_stack->head)
		{
			if (shift_info->b_direction == R)
				ft_rx(b_stack, "rb");
			else
				ft_rrx(b_stack, "rrb");
		}
	}
	ft_px(a_stack, b_stack, "pa");
}

void	ft_solve_b(t_stack *a_stack, t_stack *b_stack)
{
	t_shift_info	*shift_info;

	shift_info = (t_shift_info *)malloc(sizeof(t_shift_info));
	if (!shift_info)
		ft_error();
	shift_info->a_elem = NULL;
	shift_info->b_elem = NULL;
	shift_info->a_direction = R;
	shift_info->b_direction = R;
	shift_info->size = 0;
	shift_info->is_set = false;
	while (b_stack->size)
	{
		shift_info->is_set = false;
		ft_opt_direction(a_stack, b_stack, shift_info);
		ft_move_b(a_stack, b_stack, shift_info);
	}
	free(shift_info);
}
