/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:24:20 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 00:45:14 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (false);
	while (stack->index != -1)
	{
		if (stack->next->index == -1)
			break ;
		if (stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	is_almost_sorted(t_node *stack)
{
	long	node_count;

	if (!stack)
		return (false);
	node_count = node_counter(stack);
	while (node_count > 0)
	{
		if (is_sorted(stack))
			return (true);
		rotate_util_func(&stack);
		node_count--;
	}
	return (false);
}