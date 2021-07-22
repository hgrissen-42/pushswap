/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:42:10 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 20:38:30 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_norm(t_stack *a_stack, t_stack *b_stack, t_info *info)
{
	if (info->a_dir == R)
		ft_rr(a_stack, b_stack, "rr");
	else
		ft_rrr(a_stack, b_stack, "rrr");
}

void	move_b(t_stack *a_stack, t_stack *b_stack, t_info *info)
{
	while (info->a_node != a_stack->head
		|| info->b_node != b_stack->head)
	{
		if (info->a_dir == info->b_dir
			&& info->a_node != a_stack->head
			&& info->b_node != b_stack->head)
			move_b_norm(a_stack, b_stack, info);
		else if (info->a_node != a_stack->head)
		{
			if (info->a_dir == R)
				ft_rx(a_stack, "ra");
			else
				ft_rrx(a_stack, "rra");
		}
		else if (info->b_node != b_stack->head)
		{
			if (info->b_dir == R)
				ft_rx(b_stack, "rb");
			else
				ft_rrx(b_stack, "rrb");
		}
	}
	ft_px(a_stack, b_stack, "pa");
}

void	solve_b(t_stack *a_stack, t_stack *b_stack)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		ft_error();
	info->a_node = NULL;
	info->b_node = NULL;
	info->a_dir = R;
	info->b_dir = R;
	info->size = 0;
	info->is_set = false;
	while (b_stack->size)
	{
		info->is_set = false;
		direct(a_stack, b_stack, info);
		move_b(a_stack, b_stack, info);
	}
	free(info);
}
