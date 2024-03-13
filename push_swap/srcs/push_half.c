/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:01:41 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/13 14:42:48 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*push_smaller_half_to_b(t_node **stack_a, t_node **stack_b, t_ope_d *ope_dict)
{
	int		push_count;
	int		initial_node_num;
	t_ope	*ope_list;

	push_count = 0;
	initial_node_num = node_counter(*stack_a);
	ope_list = NULL;
	while (push_count < initial_node_num / 2)
	{
		if ((*stack_a)->index < initial_node_num / 2)
		{
			if (add_ope_list(&ope_list, ope_dict->p))
				push(stack_a, stack_b);
			push_count++;
		}
		else
		{
			if (add_ope_list(&ope_list, ope_dict->r))
				rotate(stack_a, NULL);
		}
	}
	return (ope_list);
}

t_ope	*push_bigger_half_to_a(t_node **stack_a, t_node **stack_b, t_ope_d *ope_dict)
{
	int		push_count;
	int		initial_node_num;
	int		initial_min_index;
	t_ope	*ope_list;

	push_count = 0;
	initial_node_num = node_counter(*stack_b);
	initial_min_index = find_min_index(*stack_b);
	ope_list = NULL;
	while (push_count < (initial_node_num + 1) / 2)
	{
		if ((*stack_b)->index >= initial_node_num / 2 + initial_min_index)
		{
			if (add_ope_list(&ope_list, ope_dict->p))
				push(stack_b, stack_a);
			push_count++;
		}
		else
		{
			if (add_ope_list(&ope_list, ope_dict->r))
				rotate(stack_b, NULL);
		}
	}
	return (ope_list);
}