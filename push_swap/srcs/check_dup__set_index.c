/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup__set_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:48:09 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 14:08:30 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_dup__set_index(t_node *new_node)
{
	t_node	*stack;

	new_node->index = 0;
	stack = new_node->next->next;
	while (stack->index != -1 && stack->next->index != -1)
	{
		if (stack->num == new_node->num)
			free_stack__exit(new_node, NULL, 1);
		else if (stack->num > new_node->num)
			stack->index++;
		else if (stack->num < new_node->num)
			new_node->index++;
		stack = stack->next;
	}
}
