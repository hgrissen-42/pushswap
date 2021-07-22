/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:27:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 21:07:17 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		i;
	t_node	*current;

	i = 1;
	current = stack->head;
	while (i < stack->size)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

void	check_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_b->size == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

int	apply_ops(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(op, "sa"))
		ft_sx(a, NULL);
	else if (!ft_strcmp(op, "sb"))
		ft_sx(b, NULL);
	else if (!ft_strcmp(op, "ss"))
		ft_ss(a, b, NULL);
	else if (!ft_strcmp(op, "pa"))
		ft_px(a, b, NULL);
	else if (!ft_strcmp(op, "pb"))
		ft_px(b, a, NULL);
	else if (!ft_strcmp(op, "ra"))
		ft_rx(a, NULL);
	else if (!ft_strcmp(op, "rb"))
		ft_rx(b, NULL);
	else if (!ft_strcmp(op, "rr"))
		ft_rr(a, b, NULL);
	else if (!ft_strcmp(op, "rra"))
		ft_rrx(a, NULL);
	else if (!ft_strcmp(op, "rrb"))
		ft_rrx(b, NULL);
	else if (!ft_strcmp(op, "rrr"))
		ft_rrr(a, b, NULL);
	else
		return (0);
	return (1);
}

void	read_ops(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;

	while (get_next_line(&op))
	{
		if (apply_ops(op, stack_a, stack_b))
		{
			free(op);
			continue ;
		}
		else
			ft_error();
		free(op);
	}
	free(op);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		stack_b = (t_stack *)malloc(sizeof(t_stack));
		if (!stack_b)
			ft_error();
		stack_b->head = NULL;
		stack_b->size = 0;
		stack_b->pairs = 0;
		stack_a = create_stack(argv);
		read_ops(stack_a, stack_b);
		check_sort(stack_a, stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
