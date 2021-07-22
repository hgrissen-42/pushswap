/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:41:31 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 17:41:32 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_stack *stack, const char *name)
{
	if (stack && stack->head)
		stack->head = stack->head->next;
	if (name)
		ft_putendl(name);
}

void	ft_rr(t_stack *a, t_stack *b, const char *name)
{
	ft_rx(a, NULL);
	ft_rx(b, NULL);
	if (name)
		ft_putendl(name);
}

void	ft_rrx(t_stack *stack, const char *name)
{
	if (stack && stack->head)
		stack->head = stack->head->previous;
	if (name)
		ft_putendl(name);
}

void	ft_rrr(t_stack *a, t_stack *b, const char *name)
{
	ft_rrx(a, NULL);
	ft_rrx(b, NULL);
	if (name)
		ft_putendl(name);
}
