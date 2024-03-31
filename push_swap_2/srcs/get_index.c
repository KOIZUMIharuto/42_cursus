/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:06:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 12:56:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	get_min_max_index(t_node *stack, int sign)
{
	long	num_index;

	num_index = ((1 - sign) / 2) * LONG_MAX;
	while (stack->index != -1)
	{
		if (sign * num_index > sign * stack->index)
			num_index = stack->index;
		stack = stack->next;
	}
	return (num_index);
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
		index++;
	}
	return (-1);
}
