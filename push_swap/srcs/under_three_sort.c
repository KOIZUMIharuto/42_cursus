/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:56:31 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 19:10:16 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*under_3(t_node **stack, t_ope_d *ope_d)
{
	t_ope	*ope_l;

	ope_l = NULL;
	if (node_counter(*stack) == 3)
	{
		if (find_max_num_index(*stack) == 0)
		{
			if (add_ope_list(&ope_l, ope_d->r))
				rotate(stack, NULL);
		}
		else if (find_max_num_index(*stack) == 1)
		{
			if (add_ope_list(&ope_l, ope_d->rr))
				reverse_rotate(stack, NULL);
		}
	}
	if (!is_sorted(*stack))
		if (add_ope_list(&ope_l, ope_d->s))
			swap(stack, NULL);
	return (ope_l);
}
