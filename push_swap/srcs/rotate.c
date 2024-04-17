/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:42 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/17 14:17:24 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_util_func(t_node **stack);

bool	rotate(t_node **s_a, t_node **s_b, t_ope_l **ope_l, char *ope)
{
	if (!ope || !add_new_ope(ope_l, ope))
		return (false);
	if (s_a && *s_a && (*s_a)->index != -1 && (ope[1] == 'a' || ope[1] == 'r'))
		rotate_util_func(s_a);
	if (s_b && *s_b && (*s_b)->index != -1 && (ope[1] == 'b' || ope[1] == 'r'))
		rotate_util_func(s_b);
	return (true);
}

static void	rotate_util_func(t_node **stack)
{
	t_node	*node_tmp;

	node_tmp = (*stack)->prev;
	*stack = (*stack)->next;
	swap_util_func(&node_tmp);
}
