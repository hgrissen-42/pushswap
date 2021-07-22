/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:41:44 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 17:41:45 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_set_direction(int size, t_info new_shift_info,
		t_info *shift_info)
{
	if (!shift_info->is_set || size < shift_info->size)
	{
		shift_info->a_node = new_shift_info.a_node;
		shift_info->b_node = new_shift_info.b_node;
		shift_info->a_dir = new_shift_info.a_dir;
		shift_info->b_dir = new_shift_info.b_dir;
		shift_info->size = size;
		shift_info->is_set = true;
	}
}

void	ft_optimal_direction(t_stack *a_stack, t_stack *b_stack,
			t_node *b_node, t_info *shift_info)
{
	t_info	new_shift_info;
	int		ra_size;
	int		rra_size;
	int		rb_size;
	int		rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	new_shift_info.a_node = find_node(a_stack, b_node->index);
	new_shift_info.b_node = b_node;
	ft_estimate_direction(a_stack, new_shift_info.a_node->index,
		&ra_size, &rra_size);
	ft_estimate_direction(b_stack, b_node->index,
		&rb_size, &rrb_size);
	new_shift_info.a_dir = R;
	new_shift_info.b_dir = R;
	ft_set_direction(ft_max(ra_size, rb_size), new_shift_info, shift_info);
	new_shift_info.a_dir = RR;
	ft_set_direction(rra_size + rb_size, new_shift_info, shift_info);
	new_shift_info.b_dir = RR;
	ft_set_direction(ft_max(rra_size, rrb_size), new_shift_info, shift_info);
	new_shift_info.a_dir = R;
	ft_set_direction(ra_size + rrb_size, new_shift_info, shift_info);
}

void	ft_opt_direction(t_stack *a_stack, t_stack *b_stack,
			t_info *shift_info)
{
	int		i;
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
