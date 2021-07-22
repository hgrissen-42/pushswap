/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:41:49 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 18:18:48 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*next_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;
	t_bool	has_min;
	int		i;

	min = NULL;
	if (stack)
	{
		i = 0;
		has_min = false;
		current = stack->head;
		while (i < stack->size)
		{
			if ((current->index == -1)
				&& (!has_min || current->number < min->number))
			{
				has_min = true;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}

void	indexation(t_stack *stack)
{
	t_node	*current;
	int		index;

	index = 0;
	while (index < stack->size)
	{
		current = next_min(stack);
		current->index = index++;
	}
}
