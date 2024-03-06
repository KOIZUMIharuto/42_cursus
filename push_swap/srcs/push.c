/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:37 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 17:20:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	pop(t_node **stack);

void	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*node_tmp;

	if (!stack_from || !*stack_from || (*stack_from)->index == -1)
		return ;
	node_tmp = *stack_from;
	pop(stack_from);
	(*stack_to)->prev->next = node_tmp;
	node_tmp->prev = (*stack_to)->prev;
	(*stack_to)->prev = node_tmp;
	node_tmp->next = *stack_to;
	*stack_to = node_tmp;
}

static void	pop(t_node **stack)
{
	if ((*stack)->next == *stack)
		*stack = NULL;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = (*stack)->next;
	}
}
