/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:42:10 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 17:42:11 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_norm(t_stack *a_stack, t_stack *b_stack, t_info *shift_info)
{
	if (shift_info->a_dir == R)
		ft_rr(a_stack, b_stack, "rr");
	else
		ft_rrr(a_stack, b_stack, "rrr");
}

void	move_b(t_stack *a_stack, t_stack *b_stack, t_info *shift_info)
{
	while (shift_info->a_node != a_stack->head
		|| shift_info->b_node != b_stack->head)
	{
		if (shift_info->a_dir == shift_info->b_dir
			&& shift_info->a_node != a_stack->head
			&& shift_info->b_node != b_stack->head)
			move_b_norm(a_stack, b_stack, shift_info);
		else if (shift_info->a_node != a_stack->head)
		{
			if (shift_info->a_dir == R)
				ft_rx(a_stack, "ra");
			else
				ft_rrx(a_stack, "rra");
		}
		else if (shift_info->b_node != b_stack->head)
		{
			if (shift_info->b_dir == R)
				ft_rx(b_stack, "rb");
			else
				ft_rrx(b_stack, "rrb");
		}
	}
	ft_px(a_stack, b_stack, "pa");
}

void	solve_b(t_stack *a_stack, t_stack *b_stack)
{
	t_info	*shift_info;

	shift_info = (t_info *)malloc(sizeof(t_info));
	if (!shift_info)
		ft_error();
	shift_info->a_node = NULL;
	shift_info->b_node = NULL;
	shift_info->a_dir = R;
	shift_info->b_dir = R;
	shift_info->size = 0;
	shift_info->is_set = false;
	while (b_stack->size)
	{
		shift_info->is_set = false;
		ft_opt_direction(a_stack, b_stack, shift_info);
		move_b(a_stack, b_stack, shift_info);
	}
	free(shift_info);
}
