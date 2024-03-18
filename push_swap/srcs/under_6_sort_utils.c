/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_6_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:56:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/18 14:10:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*get_back_from_s_b(
	t_node **s_a, t_node **s_b, t_ope_d *ope_d)
{
	t_ope	*ope_l;

	ope_l = NULL;
	while ((*s_b)->index != -1)
	{
		if (!add_ope_list(&ope_l, ope_d->p))
		{
			(void)free_ope_list(ope_l, NULL);
			return (NULL);
		}
		push(s_b, s_a);
	}
	return (ope_l);
}

t_ope	*sort__pa(t_node **s_a, t_node **s_b, t_ope_ds *ope_ds)
{
	t_ope	*ope_l;
	t_ope	*ope_l_tmp;

	ope_l = under_3(s_a, ope_ds->a);
	ope_l_tmp = under_3_reverse(s_b, ope_ds->b);
	merge_ope_list(&ope_l, ope_l_tmp);
	ope_l_tmp = get_back_from_s_b(s_a, s_b, ope_ds->b);
	join_ope_list(&ope_l, ope_l_tmp);
	if (!is_all_sorted(*s_a, *s_b))
		return (free_ope_list(ope_l, NULL));
	return (ope_l);
}

t_ope	*under_3_reverse(t_node **stack, t_ope_d *ope_d)
{
	t_ope	*ope_l;

	ope_l = NULL;
	if (node_counter(*stack) == 3)
	{
		if (find_min_num_index(*stack) == 0)
		{
			if (add_ope_list(&ope_l, ope_d->r))
				rotate(stack, NULL);
		}
		else if (find_min_num_index(*stack) == 1)
		{
			if (add_ope_list(&ope_l, ope_d->rr))
				reverse_rotate(stack, NULL);
		}
	}
	if ((*stack)->index != node_counter(*stack) - 1)
		if (add_ope_list(&ope_l, ope_d->s))
			swap(stack, NULL);
	return (ope_l);
}
