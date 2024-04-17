/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:17:00 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/17 18:27:11 by hkoizumi         ###   ########.fr       */
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
	while (stack->index < stack->next->index)
		stack = stack->next;
	stack = stack->next;
	while (node_count-- > 1)
	{
		if (stack->next->index == -1)
		{
			if (stack->index > stack->next->next->index)
				return (false);
			stack = stack->next;
		}
		else
		{
			if (stack->index > stack->next->index)
				return (false);
		}
		stack = stack->next;
	}
	return (true);
}
