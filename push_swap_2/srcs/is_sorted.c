/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:24:20 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/21 17:40:44 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_all_sorted(t_node *s_a, t_node *s_b)
{
	if (!s_a || !s_b)
		return (false);
	if (node_counter(s_b) != 0 || !is_sorted(s_a))
		return (false);
	return (true);
}

bool	is_sorted(t_node *stack)
{
	long	index_tmp;

	if (!stack)
		return (false);
	index_tmp = -1;
	while (stack->index != -1)
	{
		if (stack->index <= index_tmp)
			return (false);
		index_tmp = stack->index;
		stack = stack->next;
	}
	return (true);
}
