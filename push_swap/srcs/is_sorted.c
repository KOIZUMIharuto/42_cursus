/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:17:00 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/17 14:17:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (false);
	while (stack->index != -1)
	{
		if (stack->next->index == -1)
			break ;
		if (stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	is_almost_sorted(t_node *stack)
{
	long	node_count;
	t_node	*s_tmp;

	if (!stack)
		return (false);
	node_count = node_counter(stack);
	s_tmp = stack;
	while (s_tmp->index < s_tmp->next->index)
		s_tmp = s_tmp->next;
	s_tmp = s_tmp->next;
	while (node_count-- > 1)
	{
		if (s_tmp->next->index == -1)
		{
			if (s_tmp->index > s_tmp->next->next->index)
				return (false);
			s_tmp = s_tmp->next;
		}
		else
		{
			if (s_tmp->index > s_tmp->next->index)
				return (false);
		}
		s_tmp = s_tmp->next;
	}
	return (true);
}