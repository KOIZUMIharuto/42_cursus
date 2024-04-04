/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:44 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 03:25:46 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	swap(t_node **s_a, t_node **s_b, t_ope_l **ope_l, char *ope)
{
	if (!ope_l || !ope || !add_new_ope(ope_l, ope))
		return (false);
	if (s_a && *s_a && (*s_a)->next->index != -1 && (ope[1] == 'a' || ope[1] == 's'))
		swap_util_func(s_a);
	if (s_b && *s_b && (*s_b)->next->index != -1 && (ope[1] == 'b' || ope[1] == 's'))
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
