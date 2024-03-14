/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:43 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 16:56:40 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*sub_dup_stack_func(t_node *stack);
static t_node	*free_stack_node(t_node *new_stack, t_node *new_node);

bool	dup_stack(t_node *s_a, t_node *s_b, t_node **s_a_c, t_node **s_b_c)
{
	*s_a_c = sub_dup_stack_func(s_a);
	*s_b_c = sub_dup_stack_func(s_b);
	if (!*s_a_c || !*s_b_c)
	{
		free_stack__exit(*s_a_c, *s_b_c, -1);
		return (false);
	}
	return (true);
}

static t_node	*sub_dup_stack_func(t_node *stack)
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
