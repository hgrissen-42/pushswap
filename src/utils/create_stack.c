/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:41:21 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 17:41:22 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_error();
	new->number = number;
	new->index = -1;
	new->keep_in_stack = false;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	add_node(t_stack *stack, t_node *node)
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
		}
		stack->size++;
	}
}

t_stack	*create_stack(char **av)
{
	t_stack	*ret;
	    int	i;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		ft_error();
	ret->head = NULL;
	ret->mkp_head = NULL;
	ret->size = 0;
	ret->pairs = 0;
	i = 1;
	while (av[i])
	{
		if (!ft_isdigits(av[i]) || !ft_isint(ft_atol(av[i])))
			ft_error();
		add_node(ret, create_node(ft_atol(av[i])));
		i++;
	}
	check_duplicates(ret);
	return (ret);
}
