/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:16:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/17 14:16:27 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	node_counter(t_node *stack)
{
	long	node_count;

	if (!stack)
		return (-1);
	node_count = 0;
	while (stack->index != -1)
	{
		node_count++;
		stack = stack->next;
	}
	return (node_count);
}
