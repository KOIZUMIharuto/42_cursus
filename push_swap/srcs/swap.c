/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:44 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/01 20:38:51 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sub_swap_func(t_node **stack);

void	swap(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a)
		sub_swap_func(stack_a);
	if (stack_b && *stack_b)
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
