/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:16:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/17 14:16:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	join_node_and_list(t_node **stack_list, t_node *next_node)
{
	if (!stack_list || !*stack_list || !next_node)
		return ;
	next_node->prev = (*stack_list)->prev;
	(*stack_list)->prev->next = next_node;
	next_node->next = *stack_list;
	(*stack_list)->prev = next_node;
}
