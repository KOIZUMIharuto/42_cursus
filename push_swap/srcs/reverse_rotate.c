/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 13:02:06 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sub_reverse_rotate_func(t_node **stack);

void	reverse_rotate(t_node **s_a, t_node **s_b)
{
	if (s_a && *s_a && (*s_a)->index != -1)
		sub_reverse_rotate_func(s_a);
	if (s_b && *s_b && (*s_b)->index != -1)
		sub_reverse_rotate_func(s_b);
}

static void	sub_reverse_rotate_func(t_node **stack)
{
	t_node	*node_tmp;

	node_tmp = (*stack)->prev->prev;
	*stack = (*stack)->prev->prev;
	sub_swap_func(&node_tmp);
}
