/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 12:27:46 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	r_rotate_util_func(t_node **stack);

bool	r_rotate(t_node **s_a, t_node **s_b, t_ope **ope_l, char *ope)
{
	if (!ope_l || !ope || !add_ope_list(ope_l, ope))
		return (false);
	if (s_a && *s_a && (*s_a)->index != -1)
		r_rotate_util_func(s_a);
	if (s_b && *s_b && (*s_b)->index != -1)
		r_rotate_util_func(s_b);
	return (true);
}

static void	r_rotate_util_func(t_node **stack)
{
	t_node	*node_tmp;

	node_tmp = (*stack)->prev->prev;
	*stack = (*stack)->prev->prev;
	swap_util_func(&node_tmp);
}
