/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:42 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 02:40:01 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	rotate(t_node **s_a, t_node **s_b, t_ope_l **ope_l, char *ope)
{
	if (!ope_l || !ope || !add_new_ope(ope_l, ope))
		return (false);
	if (s_a && *s_a && (*s_a)->index != -1)
		rotate_util_func(s_a);
	if (s_b && *s_b && (*s_b)->index != -1)
		rotate_util_func(s_b);
	return (true);
}

void	rotate_util_func(t_node **stack)
{
	t_node	*node_tmp;

	node_tmp = (*stack)->prev;
	*stack = (*stack)->next;
	swap_util_func(&node_tmp);
}
