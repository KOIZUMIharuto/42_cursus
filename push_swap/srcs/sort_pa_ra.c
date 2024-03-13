/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pa_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:54:45 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/13 09:30:58 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*sort_pa_ra(
	t_node **stack_a, t_node **stack_b, t_all_ope_d *ope_dict)
{
	t_ope	*ope_list;

	ope_list = under_3_sort(stack_b, ope_dict->b);
	while (node_counter(*stack_b) > 0)
	{
		if (add_ope_list(&ope_list, ope_dict->b->p))
			push(stack_b, stack_a);
		if (add_ope_list(&ope_list, ope_dict->a->r))
			rotate(stack_a, NULL);
	}
	return (ope_list);
}
