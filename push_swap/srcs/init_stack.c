/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:02:59 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 12:25:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*init_stack(void)
{
	t_node	*stack;

	stack = (t_node *)malloc (sizeof(t_node));
	if (!stack)
		return (NULL);
	stack->next = stack;
	stack->prev = stack;
	stack->num = 0;
	stack->index = -1;
	return (stack);
}
