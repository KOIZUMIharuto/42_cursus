/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:46:03 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/13 14:43:07 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*under_3_sort(t_node **stack, t_ope_d *ope_dict)
{
	t_ope	*ope_list;

	ope_list = NULL;
	if (node_counter(*stack) == 3)
	{
		if (find_max_num_index(*stack) == 0)
		{
			if (add_ope_list(&ope_list, ope_dict->r))
				rotate(stack, NULL);
		}
		else if (find_max_num_index(*stack) == 1)
		{
			if (add_ope_list(&ope_list, ope_dict->rr))
				reverse_rotate(stack, NULL);
		}
	}
	if (!is_sorted(*stack))
		if (add_ope_list(&ope_list, ope_dict->s))
			swap(stack, NULL);
	return (ope_list);
}
