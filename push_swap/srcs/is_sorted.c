/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:24:20 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 12:35:04 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_node *stack_a, t_node *stack_b, int node_num)
{
	int		index_count;

	if (!stack_a || !stack_b || counter(stack_a) + counter(stack_b) != node_num)
		free_stack__exit(stack_a, stack_b, 1);
	if (counter(stack_b) != 0)
		return (false);
	index_count = 0;
	while (stack_a->index != -1)
	{
		if (stack_a->index != index_count)
			return (false);
		index_count++;
		stack_a = stack_a->next;
	}
	if (index_count != node_num)
		free_stack__exit(stack_a, stack_b, 1);
	return (true);
}
