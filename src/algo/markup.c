/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:42:00 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 17:42:01 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mode_greater(t_stack *stack, t_node *markup_head)
{
	int				index;
	int				pairs;
	t_node			*current;

	pairs = 0;
	if (stack)
	{
		index = markup_head->index;
		markup_head->keep_in_stack = true;
		current = markup_head->next;
		while (current != markup_head)
		{
			if (current->index > index)
			{
				pairs++;
				index = current->index;
				current->keep_in_stack = true;
			}
			else
				current->keep_in_stack = false;
			current = current->next;
		}
	}
	return (pairs);
}

void	markup_stack(t_stack *stack)
{
	int				i;
	int				current_pairs;
	t_node			*current;

	if (stack)
	{
		i = 0;
		current = stack->head;
		while (i < stack->size)
		{
			current_pairs = mode_greater(stack, current);
			if (current_pairs > stack->pairs)
			{
				stack->mkp_head = current;
				stack->pairs = current_pairs;
			}
			else if (current_pairs == stack->pairs
				&& (!stack->mkp_head
					|| current->number < stack->mkp_head->number))
				stack->mkp_head = current;
			i++;
			current = current->next;
		}
		mode_greater(stack, stack->mkp_head);
	}
}
