/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:24:20 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/12 20:18:33 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_all_sorted(t_node *stack_a, t_node *stack_b, int node_num)
{
	if (!stack_a || !stack_b || node_counter(stack_a) + node_counter(stack_b) != node_num)
		free_stack__exit(stack_a, stack_b, 1);
	if (node_counter(stack_b) != 0 || !is_sorted(stack_a))
		return (false);
	if (node_counter(stack_a) != node_num)
		free_stack__exit(stack_a, stack_b, 1);
	return (true);
}

bool	is_sorted(t_node *stack)
{
	int		index_count;

	index_count = -1;
	while (stack->index != -1)
	{
		if (stack->index <= index_count)
			return (false);
		index_count = stack->index;
		stack = stack->next;
	}
	return (true);
}