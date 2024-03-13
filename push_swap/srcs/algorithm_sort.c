/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:42:32 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/13 14:44:50 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*recursive_sort(
	t_node **stack_a, t_node **stack_b, t_all_ope_d *ope_dict);
static int	push_ope_counter(t_ope *ope_list);

t_ope	*algorithm_sort(
	t_node **stack_a, t_node **stack_b, t_all_ope_d *ope_dict)
{
	t_ope	*ope_list;
	t_ope	*ope_list_tmp;

	ope_list = push_smaller_half_to_b(stack_a, stack_b, ope_dict->a);
	ope_list_tmp = recursive_sort(stack_a, stack_b, ope_dict);
	join_ope_list(&ope_list, ope_list_tmp);
	while ((*stack_a)->index != 0)
	{
		if (add_ope_list(&ope_list, ope_dict->a->p))
			push(stack_a, stack_b);
	}
	ope_list_tmp = recursive_sort(stack_a, stack_b, ope_dict);
	join_ope_list(&ope_list, ope_list_tmp);
	return (ope_list);
}

static t_ope	*recursive_sort(
	t_node **stack_a, t_node **stack_b, t_all_ope_d *ope_dict)
{
	t_ope	*ope_list;
	t_ope	*ope_list_tmp;
	int		push_count;

	if (node_counter(*stack_b) <= 3)
		return (sort_pa_ra(stack_a, stack_b, ope_dict));
	ope_list = push_bigger_half_to_a(stack_a, stack_b, ope_dict->b);
	push_count = push_ope_counter(ope_list);
	ope_list_tmp = recursive_sort(stack_a, stack_b, ope_dict);
	join_ope_list(&ope_list, ope_list_tmp);
	while (push_count-- > 1)
		if (add_ope_list(&ope_list, ope_dict->a->p))
			push(stack_a, stack_b);
	ope_list_tmp = recursive_sort(stack_a, stack_b, ope_dict);
	join_ope_list(&ope_list, ope_list_tmp);
	return (ope_list);
}

static int	push_ope_counter(t_ope *ope_list)
{
	int		push_count;

	if (!ope_list)
		return (-1);
	push_count = 1;
	while (ope_list)
	{
		if (ope_list->ope[0] == 'p')
			push_count++;
		ope_list = ope_list->next;
	}
	return (push_count);
}
