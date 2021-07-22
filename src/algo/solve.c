/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:42:14 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 20:40:57 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alignment(t_stack *a_stack)
{
	t_node			*current;
	int				ra_size;
	int				rra_size;

	if (a_stack && a_stack->head)
	{
		ra_size = 0;
		current = a_stack->head;
		while (current->index != 0)
		{
			ra_size++;
			current = current->next;
		}
		rra_size = 0;
		current = a_stack->head;
		while (current->index != 0)
		{
			rra_size++;
			current = current->previous;
		}
		while (a_stack->head->index != 0 && (ra_size < rra_size))
			ft_rx(a_stack, "ra");
		while (a_stack->head->index != 0 && !(ra_size < rra_size))
			ft_rrx(a_stack, "rra");
	}
}

void	solve(t_stack *a_stack)
{
	t_stack			*b_stack;

	b_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!b_stack)
		ft_error();
	b_stack->head = NULL;
	b_stack->size = 0;
	b_stack->pairs = 0;
	b_stack->mkp_head = NULL;
	solve_a(a_stack, b_stack);
	solve_b(a_stack, b_stack);
	alignment(a_stack);
	free_stack(b_stack);
	free_stack(a_stack);
}
