/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:44 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 12:28:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	swap(t_node **s_a, t_node **s_b, t_ope **ope_l, char *ope)
{
	if (!ope_l || !ope || !add_ope_list(ope_l, ope))
		return (false);
	if (s_a && *s_a && (*s_a)->next->index != -1)
		swap_util_func(s_a);
	if (s_b && *s_b && (*s_b)->next->index != -1)
		swap_util_func(s_b);
	return (true);
}

void	swap_util_func(t_node **stack)
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