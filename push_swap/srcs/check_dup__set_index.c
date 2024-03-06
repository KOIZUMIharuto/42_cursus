/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup__set_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:48:09 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 12:02:08 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_dup__set_index(t_node *stack, t_node *new_node)
{
	int		new_index;

	new_index = 0;
	stack = stack->next;
	while (stack->index != -1 && stack->next->index != -1)
	{
		if (stack->num == new_node->num)
			free_stack__exit(stack, NULL, 1);
		else if (stack->num > new_node->num)
			stack->index++;
		else if (stack->num < new_node->num)
			new_index++;
		stack = stack->next;
	}
	new_node->index = new_index;
}
