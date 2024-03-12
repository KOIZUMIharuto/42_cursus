/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:59:02 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/12 22:45:10 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*sort_stack_for_compare(
	t_node **stack_a, t_node **stack_b, int num, t_all_ope_d *ope_dict);
static t_ope	*push_b_smaller_ones_r(
	t_node **stack_a, t_node **stack_b, int num, t_ope_d *ope_dict);
static t_ope	*push_b_smaller_ones_rr(
	t_node **stack_a, t_node **stack_b, int num, t_ope_d *ope_dict);

t_ope	*under_6_sort(
	t_node **stack_a, t_node **stack_b, int num, t_all_ope_d *ope_dict)
{
	t_node	*stack_a_copy;
	t_node	*stack_b_copy;
	t_ope	*ope_list_1;
	t_ope	*ope_list_2;

	stack_a_copy = duplicate_stack(*stack_a);
	stack_b_copy = duplicate_stack(*stack_b);
	ope_list_1 = sort_stack_for_compare(stack_a, stack_b, num, ope_dict);
	ope_list_2 = sort_stack_for_compare(&stack_a_copy, &stack_b_copy, num, ope_dict);
	if (!ope_list_1 || !ope_list_2)
	{
		free_stack__exit(stack_a_copy, stack_b_copy, -1);
		return (free_ope_list(ope_list_1, ope_list_2));
	}
	if (ope_counter(ope_list_1) > ope_counter(ope_list_2))
	{
		free_stack__exit(*stack_a, *stack_b, -1);
		*stack_a = stack_a_copy;
		*stack_b = stack_b_copy;
		(void)free_ope_list(ope_list_1, NULL);
		return (ope_list_2);
	}
	free_stack__exit(stack_a_copy, stack_b_copy, -1);
	(void)free_ope_list(NULL, ope_list_2);
	return (ope_list_1);
}

static t_ope	*sort_stack_for_compare(
	t_node **stack_a, t_node **stack_b, int num, t_all_ope_d *ope_dict)
{
	static bool is_first = true;
	t_ope		*ope_list;
	t_ope		*ope_list_tmp;

	if (is_first)
		ope_list = push_b_smaller_ones_r(stack_a, stack_b, num, ope_dict->a);
	else
		ope_list = push_b_smaller_ones_rr(stack_a, stack_b, num, ope_dict->a);
	if (!ope_list)
		return (NULL);
	ope_list_tmp = sort__get_back(stack_a, stack_b, num, ope_dict);
	if (!ope_list_tmp)
		return (free_ope_list(ope_list, NULL));
	join_ope_list(&ope_list, ope_list_tmp);
	is_first = !is_first;
	return (ope_list);
}

static t_ope	*push_b_smaller_ones_r(
	t_node **stack_a, t_node **stack_b, int num, t_ope_d *ope_dict)
{
	t_ope	*ope_list;
	int		move_count;

	ope_list = NULL;
	move_count = 0;
	while (move_count < num - 3)
	{
		if ((*stack_a)->index < num - 3)
		{
			if (!add_ope_list(&ope_list, ope_dict->p))
				return (NULL);
			push(stack_a, stack_b);
			move_count++;
		}
		else
		{
			if (!add_ope_list(&ope_list, ope_dict->r))
				return (NULL);
			rotate(stack_a, NULL);
		}
	}
	return (ope_list);
}

static t_ope	*push_b_smaller_ones_rr(
	t_node **stack_a, t_node **stack_b, int num, t_ope_d *ope_dict)
{
	t_ope	*ope_list;
	int		move_count;

	ope_list = NULL;
	move_count = 0;
	while (move_count < num - 3)
	{
		if ((*stack_a)->index < num - 3)
		{
			if (!add_ope_list(&ope_list, ope_dict->p))
				return (NULL);
			push(stack_a, stack_b);
			move_count++;
		}
		else
		{
			if (!add_ope_list(&ope_list, ope_dict->rr))
				return (NULL);
			reverse_rotate(stack_a, NULL);
		}
	}
	return (ope_list);
}

// reverse sort
// 2 1 ->
// 1 2 -> sa

// 3 2 1 -> 
// 2 3 1 -> sa
// 2 1 3 -> rra
// 3 1 2 -> rra sa
// 1 3 2 -> ra
// 1 2 3 -> ra sa
