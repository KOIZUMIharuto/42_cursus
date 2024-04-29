/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:16:47 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/29 12:21:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	get_max_index(t_node *stack)
{
	long	max_num_index;

	max_num_index = -1;
	while (stack->index != -1)
	{
		if (max_num_index < stack->index)
			max_num_index = stack->index;
		stack = stack->next;
	}
	return (max_num_index);
}

long	get_min_index(t_node *stack)
{
	long	min_num_index;

	min_num_index = LONG_MAX;
	while (stack->index != -1)
	{
		if (min_num_index > stack->index)
			min_num_index = stack->index;
		stack = stack->next;
	}
	return (min_num_index);
}

long	get_pos(t_node *stack, long index)
{
	long	pos;

	pos = 0;
	while (stack->index != -1)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
