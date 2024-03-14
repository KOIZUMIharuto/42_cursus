/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:44 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 13:02:06 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **s_a, t_node **s_b)
{
	if (s_a && *s_a && (*s_a)->next->index != -1)
		sub_swap_func(s_a);
	if (s_b && *s_b && (*s_b)->next->index != -1)
		sub_swap_func(s_b);
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
