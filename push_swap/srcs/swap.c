/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:44 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/12 13:03:01 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next->index != -1)
		sub_swap_func(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next->index != -1)
		sub_swap_func(stack_b);
}

void	sub_swap_func(t_node **stack)
{
	t_node	*node_tmp;

	if (!stack || *stack == (*stack)->next)
		return ;
	node_tmp = (*stack)->next;
	(*stack)->next = node_tmp->next;
	node_tmp->next->prev = *stack;
	node_tmp->next = *stack;
	node_tmp->prev = (*stack)->prev;
	(*stack)->prev->next = node_tmp;
	(*stack)->prev = node_tmp;
	*stack = node_tmp;
}
