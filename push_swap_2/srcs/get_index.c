/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:06:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 02:25:07 by xxxx             ###   ########.fr       */
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

long	get_index_index(t_node *stack, long index)
{
	long	index_index;

	index_index = 0;
	while (stack->index != -1)
	{
		if (stack->index == index)
			return (index_index);
		stack = stack->next;
		index_index++;
	}
	return (-1);
}
