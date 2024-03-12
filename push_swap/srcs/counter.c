/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/12 20:20:26 by xxxx             ###   ########.fr       */
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

int	ope_counter(t_ope *ope_list)
{
	int		ope_count;

	if (!ope_list)
		return (-1);
	ope_count = 0;
	while (ope_list)
	{
		ope_list = ope_list->next;
		ope_count++;
	}
	return (ope_count);
}