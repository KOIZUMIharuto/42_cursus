/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max_num_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 19:42:50 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_num_index(t_node *stack)
{
	int	min_num_index;
	int	min_index;

	min_num_index = 0;
	min_index = find_min_index(stack);
	while (stack->index != -1)
	{
		if (stack->index == min_index)
			break ;
		min_num_index++;
		stack = stack->next;
	}
	return (min_num_index);
}

int	find_min_index(t_node *stack)
{
	int	min_index;

	min_index = stack->index;
	while (stack->index != -1)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

int	find_max_num_index(t_node *stack)
{
	int	max_num_index;
	int	index_tmp;
	int	max_index;

	max_num_index = 0;
	index_tmp = 0;
	max_index = stack->index;
	while (stack->index != -1)
	{
		if (stack->index > max_index)
		{
			max_num_index += index_tmp;
			index_tmp = 0;
			max_index = stack->index;
		}
		index_tmp++;
		stack = stack->next;
	}
	return (max_num_index);
}
