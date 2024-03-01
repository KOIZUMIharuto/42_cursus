/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:42 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/01 20:41:43 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sub_rotate_func(t_node **stack);

void	rotate(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a)
		sub_rotate_func(stack_a);
	if (stack_b && *stack_b)
		sub_rotate_func(stack_b);
}

static void	sub_rotate_func(t_node **stack)
{
	t_node	*node_tmp;

	node_tmp = (*stack)->prev;
	*stack = (*stack)->next;
	swap(&node_tmp, NULL);
}
