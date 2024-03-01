/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:48:09 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/01 20:24:58 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	join_list_and_node(t_node **stack_list, t_node *next_node)
{
	if (!*stack_list || !next_node)
		free_stack_exit(NULL, NULL, 1);
	next_node->prev = (*stack_list)->prev;
	(*stack_list)->prev->next = next_node;
	next_node->next = *stack_list;
	(*stack_list)->prev = next_node;
}

void	check_dup_find_index(t_node *stack, t_node *new_node)
{
	int		new_index;

	new_index = 0;
	stack = stack->next;
	while (stack->index != -1 && stack->next->index != -1)
	{
		if (stack->num == new_node->num)
			free_stack_exit(stack, NULL, 1);
		else if (stack->num > new_node->num)
			stack->index++;
		else if (stack->num < new_node->num)
			new_index++;
		stack = stack->next;
	}
	new_node->index = new_index;
}
