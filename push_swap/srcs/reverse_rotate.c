/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/12 12:55:00 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sub_reverse_rotate_func(t_node **stack);

void	reverse_rotate(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->index != -1)
		sub_reverse_rotate_func(stack_a);
	if (stack_b && *stack_b && (*stack_b)->index != -1)
		sub_reverse_rotate_func(stack_b);
}

static void	sub_reverse_rotate_func(t_node **stack)
{
	t_node	*node_tmp;

	node_tmp = (*stack)->prev->prev;
	*stack = (*stack)->prev->prev;
	sub_swap_func(&node_tmp);
}
