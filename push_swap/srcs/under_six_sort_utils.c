/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:01:23 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/12 22:44:18 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*under_3_reverse_sort(t_node **stack, t_ope_d *ope_dict);
static t_ope	*get_back_stack_b(
	t_node **stack_a, t_node **stack_b, t_ope_d *ope_dict);

t_ope	*sort__get_back(
	t_node **stack_a, t_node **stack_b, int num, t_all_ope_d *ope_dict)
{
	t_ope	*ope_list;
	t_ope	*ope_list_tmp;

	ope_list = under_3_sort(stack_a, num, ope_dict->a);
	ope_list_tmp = under_3_reverse_sort(stack_b, ope_dict->b);
	join_ope_list(&ope_list, ope_list_tmp);
	ope_list_tmp = get_back_stack_b(stack_a, stack_b, ope_dict->b);
	join_ope_list(&ope_list, ope_list_tmp);
	if (!is_all_sorted(*stack_a, *stack_b, num))
		return (free_ope_list(ope_list, NULL));
	return (ope_list);
}

static t_ope	*under_3_reverse_sort(t_node **stack, t_ope_d *ope_dict)
{
	t_ope	*ope_list;

	ope_list = NULL;
	if (node_counter(*stack) == 3)
	{
		if ((*stack)->index == 0)
		{
			if (add_ope_list(&ope_list, ope_dict->r))
				rotate(stack, NULL);
		}
		else if ((*stack)->next->index == 0)
		{
			if (add_ope_list(&ope_list, ope_dict->rr))
				reverse_rotate(stack, NULL);
		}
	}
	if ((*stack)->index != node_counter(*stack) - 1)
		if (add_ope_list(&ope_list, ope_dict->s))
			swap(stack, NULL);
	return (ope_list);
}

static t_ope	*get_back_stack_b(
	t_node **stack_a, t_node **stack_b, t_ope_d *ope_dict)
{
	t_ope	*ope_list;

	ope_list = NULL;
	while ((*stack_b)->index != -1)
	{
		if (!add_ope_list(&ope_list, ope_dict->p))
		{
			free_ope_list(ope_list, NULL);
			return (NULL);
		}
		push(stack_b, stack_a);
	}
	return (ope_list);
}