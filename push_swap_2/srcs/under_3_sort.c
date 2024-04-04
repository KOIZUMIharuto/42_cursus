/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_3_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:57:51 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 05:49:27 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	under_3_sort(t_node **s_a, t_ope_l **ope_l)
{
	long	max_num_index;

	if (node_counter(*s_a) == 3)
	{
		max_num_index = get_max_index(*s_a);
		if (get_index_index(*s_a, max_num_index) == 0)
		{
			if (!rotate(s_a, NULL, ope_l, "ra"))
				return (false);
		}
		else if (get_index_index(*s_a, max_num_index) == 1)
		{
			if (!r_rotate(s_a, NULL, ope_l, "rra"))
				return (false);
		}
	}
	if (!is_sorted(*s_a))
		if (!swap(s_a, NULL, ope_l, "sa"))
			return (false);
	return (true);
}
