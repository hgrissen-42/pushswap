/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:42:04 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 17:42:05 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_pb(t_stack *a_stack)
{
	int		i;
	t_node	*current;

	if (a_stack)
	{
		i = 0;
		current = a_stack->head;
		while (i < a_stack->size)
		{
			if (!current->keep_in_stack)
				return (true);
			i++;
			current = current->next;
		}
	}
	return (false);
}

t_bool	check_sa(t_stack *a_stack)
{
	int	current_pairs;

	if (a_stack && a_stack->size >= 2)
	{
		ft_sx(a_stack, NULL);
		current_pairs = mode_greater(a_stack, a_stack->mkp_head);
		ft_sx(a_stack, NULL);
		mode_greater(a_stack, a_stack->mkp_head);
		if (current_pairs > a_stack->pairs)
			return (true);
	}
	return (false);
}

void	solve_a(t_stack *a_stack, t_stack *b_stack)
{
	while (check_pb(a_stack))
	{
		if (check_sa(a_stack))
		{
			ft_sx(a_stack, "sa");
			a_stack->pairs = mode_greater(a_stack, a_stack->mkp_head);
		}
		else if (a_stack->head->keep_in_stack == false)
			ft_px(b_stack, a_stack, "pb");
		else
			ft_rx(a_stack, "ra");
	}
}
