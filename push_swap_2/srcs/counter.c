/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/21 13:29:45 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	node_counter(t_node *stack)
{
	int	node_count;

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
