/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:48:09 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/01 18:47:19 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	join_list_and_node(t_node **prev_node, t_node *next_node)
{
	t_node	*node_tmp;

	if (!*prev_node && !next_node)
		free_stack_exit(NULL, NULL, 1);
	if (!*prev_node)
	{
		*prev_node = next_node;
		(*prev_node)->prev = NULL;
		(*prev_node)->next = NULL;
	}
	else
	{
		node_tmp = *prev_node;
		while (node_tmp->next)
			node_tmp = node_tmp->next;
		node_tmp->next = next_node;
		if (next_node)
			(next_node)->prev = node_tmp;
	}
}

void	check_dup_find_index(t_node *stack, t_node *new_node)
{
	int		new_index;

	new_index = 0;
	while (stack && stack->next)
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
