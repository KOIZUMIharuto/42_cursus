/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:25:31 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/12 22:00:30 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*free_stack_node(t_node *new_stack, t_node *new_node);

t_node	*duplicate_stack(t_node *stack)
{
	t_node	*new_stack;
	t_node	*new_node;

	if (!stack)
		return (NULL);
	new_stack = init_stack();
	if (!new_stack)
		return (NULL);
	while (stack->index != -1)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return (free_stack_node(new_stack, new_node));
		new_node->num = stack->num;
		new_node->index = stack->index;
		if (!join_node_and_list(&new_stack, new_node))
			return (free_stack_node(new_stack, new_node));
		stack = stack->next;
	}
	new_stack = new_stack->next;
	return (new_stack);
}

static t_node	*free_stack_node(t_node *new_stack, t_node *new_node)
{
	free_stack(new_stack);
	free(new_node);
	return (NULL);
}