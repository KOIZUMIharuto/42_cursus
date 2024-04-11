/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/04 14:46:48 by xxxx             ###   ########.fr       */
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
