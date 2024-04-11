/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:48:09 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/04 12:41:39 by xxxx             ###   ########.fr       */
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